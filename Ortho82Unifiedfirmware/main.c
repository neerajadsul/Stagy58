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

// Declare your global variables here

void main(void)
{
// Declare your local variables here
unsigned char n;
uint8_t state = 0;

// Check the reset source
n=RST.STATUS;
if (n & RST_PORF_bm)
	{
	// Power on reset

	}
else if (n & RST_EXTRF_bm)
	{
	// External reset

	}
else if (n & RST_BORF_bm)
	{
	// Brown out reset

	}
else if (n & RST_WDRF_bm)
	{
	// Watchdog reset

	}
else if (n & RST_PDIRF_bm)
	{
	// Program and debug interface reset

	}
else if (n & RST_SRF_bm)
	{
	// Software reset

	}
// Clear the reset flag
RST.STATUS=n;

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
n=(PMIC.CTRL & (~(PMIC_RREN_bm | PMIC_IVSEL_bm | PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm))) |
	PMIC_LOLVLEN_bm;
CCP=CCP_IOREG_gc;
PMIC.CTRL=n;
// Set the default priority for round-robin scheduling
PMIC.INTPRI=0x00;
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
DACB.CTRLA=0;

// Analog Comparator(s) for PORTA initialization
aca_init();

// Globally enable interrupts
#asm("sei")

// USB Controller initialization in Full Speed, Device mode
usb_init_device(&usb_config);

// Wait for the USB device to be enumerated by the host
while (!usb_enumerated);

// Wait 1.5 seconds for the operating system to
// load any drivers needed by the USB device
delay_ms(1500);


while (1)
      {
      // Place your code here
	  //uint8_t rows = PORTC.IN;
	  uint8_t i = 0;
	  uint8_t row_mask = 0x1;
	  uint8_t ch = 0;
	  //if (rows & 0b1) // if PE0 is high
	  //{
		  //state += 1;
	  //}
	  //if (state > 1) {
		  //printf("PE0 pressed!");
		  //usb_keyboard_keypress(KS_2_AT, KM_LEFT_SHIFT);
		  //state = 0;
	  //}
	  
	  //printf("Rows: ");
	  //for (i=0;i<5;i++)
	  //{
		  //ch = '0' + (row_mask & rows);
		  //row_mask <<= 1;
		  //putchar(ch);
	  //}
	  printf("%d \r\n", PORTC.IN);
	  
	  //usb_keyboard_sendkeys();
	  delay_ms(500);

      }
}
