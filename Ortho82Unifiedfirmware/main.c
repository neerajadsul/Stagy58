/*******************************************************
Project : Ortho82UnifiedKeyboard
Version : 1.0
Date    : 15/07/2023
Author  : Neeraj Adsul
Company : 125 Systems
Comments:


Chip type               : ATxmega32A4U
Program type            : Application
AVR Core Clock frequency: 24.000000 MHz
Memory model            : Small
Data Stack size         : 1024
*******************************************************/

// I/O Registers definitions
#include <xmega32a4u.h>

// USARTE0 is used as the default input
// device by the 'getchar' function.
#define _ALTERNATE_GETCHAR_
// USARTE0 is used as the default output
// device by the 'putchar' function.
#define _ALTERNATE_PUTCHAR_
// Standard Input/Output functions
#include <stdio.h>
#include <stdint.h>
// Delay functions
#include <delay.h>

// Clock System initialization function
#include "clock_init.h"

// Event System initialization function
#include "event_system_init.h"

// I/O Ports initialization function
#include "ports_init.h"

// Timers/Counters initialization functions
#include "timers_init.h"

// RTC initialization function
#include "rtc_init.h"

// Watchdog Timer initialization function
#include "watchdog_init.h"

// USARTs initialization functions
#include "usarts_init.h"

// ADC initialization functions
#include "adc_init.h"

// Analog Comparator(s) initialization function(s)
#include "analog_comp_init.h"

// SPI initialization functions
#include "spi_init.h"

// TWI initialization functions
#include "twi_init.h"

// USB Device functions
#include <usb_device.h>

// USB Human Interface Device functions
#include <usb_hid.h>

// USB initialization
#include "usb_init.h"

#include "keyboard.h"

#define USE_USB_CONNECTION	0

// Declare your global variables here
extern USB_KEYBOARD_t usb_keyboard;
extern uint8_t keys[N_COLS];
extern char key_buffer[N_KEYS_BUFFER];
extern volatile uint8_t key_buffer_index;
extern unsigned char usb_putbuf(void *buffer, unsigned short length);
unsigned char tx_buffer[8] = {0};
int release_keys(void); 

void main(void)
{
	// Declare your local variables here
	unsigned char n;
	char ch;
	uint8_t state = 0, left_or_right = 0;
	//uint8_t i;
	uint8_t modifier, key;
	
	// Interrupt system initialization
	// Optimize for speed
#pragma optsize-
	// Make sure the interrupts are disabled
#asm("cli")
	// Low level interrupt: On
	// Round-robin scheduling for low level interrupt: Off
	// Medium level interrupt: Off
	// High level interrupt: Off
	// The interrupt vectors will be placed at the start of the Application FLASH section
	n = (PMIC.CTRL & (~(PMIC_RREN_bm | PMIC_IVSEL_bm | PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm))) |
		PMIC_LOLVLEN_bm;
	CCP = CCP_IOREG_gc;
	PMIC.CTRL = n;
	// Set the default priority for round-robin scheduling
	PMIC.INTPRI = 0x00;
	// Restore optimization for size if needed
#pragma optsize_default

	// Watchdog timer initialization
	watchdog_init();

	// System clocks initialization
	system_clocks_init();

	// Event system initialization
	event_system_init();

	// Ports initialization
	ports_init();

	// Virtual Ports initialization
	vports_init();

	// Timer/Counter TCC0 is disabled
	tc0_disable(&TCC0);

	// Timer/Counter TCC1 is disabled
	tc1_disable(&TCC1);

	// Timer/Counter TCD0 is disabled
	tc0_disable(&TCD0);

	// Timer/Counter TCD1 is disabled
	tc1_disable(&TCD1);

	// Timer/Counter TCE0 is disabled
	tc0_disable(&TCE0);

	// RTC initialization
	rtcxm_init();

	// USARTC0 is disabled
	usart_disable(&USARTC0);

	// USARTC1 is disabled
	usart_disable(&USARTC1);

	// USARTD0 is disabled
	usart_disable(&USARTD0);

	// USARTD1 is disabled
	usart_disable(&USARTD1);

	// USARTE0 initialization
	usarte0_init();

	// SPIC initialization
	spic_init();

	// SPID initialization
	spid_init();

	// TWIC initialization
	twic_init();

	// TWIE initialization
	twie_init();

	// ADCA initialization
	adca_init();

	// DACB is disabled
	DACB.CTRLA = 0;

	// Analog Comparator(s) for PORTA initialization
	aca_init();

	// Globally enable interrupts
#asm("sei")

	if (USE_USB_CONNECTION) {
		// USB Controller initialization in Full Speed, Device mode
		usb_init_device(&usb_config);
		// Wait for the USB device to be enumerated by the host
		while (!usb_enumerated);

		// Wait 1.5 seconds for the operating system to
		// load any drivers needed by the USB device
		delay_ms(1500);
	}
    
	LED_ON;
	left_or_right = LEFT_RIGHT_PORT.IN & LEFT_RIGHT_PIN_bm;
	
	if (left_or_right==LEFT_HALF)
	{
		printf("<LEFT>\n");
	} else {
		printf("<RIGHT>\n");
	}
	
	show_scanmap(left_or_right);
	
	while (1)
		{
			// Process input from right half
			if (left_or_right == LEFT_HALF && rx_counter_usarte0 > 0)
			{
				ch = getchar();
			}

			if (scan_keys(left_or_right))
			{
				//log_keys();	
			}
				
				
			if (left_or_right == RIGHT_HALF)
			{
				// Send key-presses to Left-Half
			}
				
			delay_ms(50);
		}
}


int release_keys() 
{
	uint8_t i;

	for ( i = 0; i < 8; i++)
	{
		tx_buffer[i] = 0;
	}
	usb_putbuf(tx_buffer, 8);
	delay_ms(10);
	return 0;
}
