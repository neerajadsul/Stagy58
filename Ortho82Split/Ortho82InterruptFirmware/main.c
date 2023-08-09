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

// Delay functions
#include <delay.h>

// Clock System initialization function
#include "clock_init.h"

// Event System initialization function
#include "event_system_init.h"

// I/O Ports initialization function
#include "ports_init.h"

// USARTs initialization functions
#include "usarts_init.h"

// USB Device functions
#include <usb_device.h>

// USB Human Interface Device functions
#include <usb_hid.h>

// USB initialization
#include "usb_init.h"

// Declare your global variables here
volatile char intbuf = 0;
volatile char row_signal;


void main(void)
{
	// Declare your local variables here
	unsigned char n;
	char previous_row, current_row;

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

	// System clocks initialization
	system_clocks_init();

	// Event system initialization
	event_system_init();

	// Ports initialization
	ports_init();

	// Virtual Ports initialization
	vports_init();

	// USARTE0 initialization
	usarte0_init();

	// Globally enable interrupts
	#asm("sei")

	// USB Controller initialization in Full Speed, Device mode
	usb_init_device(&usb_config);
	
	// Wait for the USB device to be enumerated by the host
	while (!usb_enumerated);
	printf("USB Enum!\n");
	// Wait 1.5 seconds for the operating system to
	// load any drivers needed by the USB device
	delay_ms(1500);

	printf("Before While!\n");

	while (1)
	{
		// Place your code here
		PORTB.OUTTGL = (1 << 3);
		if (intbuf != 0)
		{
			current_row = row_signal;
			if (previous_row != current_row)
			{
				printf("%02x\n", row_signal);
				previous_row = current_row;	
			} 
			
			// Reset the PORTD interrupt status flag
			intbuf = 0;
		}
		delay_ms(100);
		

	}
}