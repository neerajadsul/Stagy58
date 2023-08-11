/**
 * Ortho82 Keyboard Firmware Main File
 * Author: Neeraj Adsul 
 * Email: neeraj[at]125systems[dot]com
 * Copyright 2023 Neeraj Adsul
*/
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <interrupt.h>

// #define _ALTERNATE_PUTCHAR_
// #define _ALTERNATE_GETCHAR_

#define LED_ON (PORTB_OUTCLR |= 0x08)
#define LED_OFF (PORTB_OUTSET |= 0x08)

// #include "system_clock.h"
// #include "ports.h"
// #include "usart.h"
#include "usb.h"
// #include "led_indicator.h"

void system_clocks_init();
void ports_init();
void usartE0_init();
void USARTE0_WriteChar(unsigned char);
int usb_init();

FILE USARTE0_stdout = FDEV_SETUP_STREAM (USARTE0_WriteChar, NULL, _FDEV_SETUP_WRITE); 

int main()
{
    // Unlock configuration
    CCP = CCP_IOREG_gc;
    // Low Level interrupts: On
    PMIC.CTRL = PMIC_LOLVLEN_bm;
    // make clkout on PORTC:7
	PORTCFG.CLKEVOUT = PORTCFG_CLKOUT_PC7_gc;
	PORTC.DIR = (1<<7); // clkout

    system_clocks_init();
    ports_init();
    usartE0_init();
	stdout = &USARTE0_stdout;    

    while (1)
    {
        LED_ON;
        _delay_ms(25);
        LED_OFF;
        _delay_ms(24);
    }

    return 0;
}


void system_clocks_init()
{
    cli();
    // Unlock Configuration
    CCP = CCP_IOREG_gc;
    // Eanble internal 32MHz RC Oscillator
    OSC.CTRL = OSC_RC32MEN_bm;
    // Wait until oscillator ready
    while(!(OSC.STATUS & OSC_RC32MRDY_bm));
    // Unlock Configuration
    CCP = CCP_IOREG_gc;
    // Configure system clock to 32MHz oscillator
    CLK.CTRL = CLK_SCLKSEL_RC32M_gc;
    // Unlock Configuration
    CCP = CCP_IOREG_gc;
    // Configure perpheral clock
    // A: divide by 2, B: divide by 2, C: divide by 1
    // CLK.PSCTRL = CLK_PSADIV0_bm | CLK_PSBCDIV_1_1_gc;
    sei();
}

void ports_init()
{
    // Red LED PB3 as output, Left-right PB2 as input
    PORTB_DIR = 0b00001000;
    PORTB_OUT = 0x00;
    PORTB_PIN3CTRL = 0b00011000;
}


void usartE0_init(void)
{
	//USARTE0 TXD: PE3
	PORTE.DIRSET = (1<<3); 
	PORTE.OUTSET = (1<<3); 

	//USARTE0 RXD: PE2
	PORTE.DIRCLR = (1<<2);
	PORTE.PIN2CTRL |= PORT_OPC_PULLUP_gc; 

	 USARTE0.BAUDCTRLA = 33; USARTE0.BAUDCTRLB = (-1<<4); // 115.2kb (BSCALE=33,BSEL=-1)
	//  USARTE0.BAUDCTRLA = 31; USARTE0.BAUDCTRLB = (-2<<4); // 230.4kb (BSCALE=31,BSEL=-2)
	//  USARTE0.BAUDCTRLA = 27; USARTE0.BAUDCTRLB = (-3<<4); // 460.8kb (BSCALE=27,BSEL=-3)
	//  USARTE0.BAUDCTRLA = 19; USARTE0.BAUDCTRLB = (-4<<4); // 921.6kb (BSCALE=19,BSEL=-4)
	//  USARTE0.BAUDCTRLA = 1; USARTE0.BAUDCTRLB = (1<<4); // 500kb (BSCALE=19,BSEL=-4)
	//  USARTE0.BAUDCTRLA = 1;   // 1Mb (BSCALE=1,BSEL=0)
	
	USARTE0.CTRLB = USART_TXEN_bm | USART_RXEN_bm; // enable tx and rx on USART
}


// Blocking Read char from USART RX
unsigned char USARTE0_ReadChar(void)
{
	while(!(USARTE0.STATUS&USART_RXCIF_bm));  // wait for RX complete

  	return USARTE0.DATA;
}

// Check if data available in USART RX
unsigned char USARTE0_RX_Available(void)
{
	return (USARTE0.STATUS&USART_RXCIF_bm);
}

void USARTE0_WriteChar(unsigned char data)
{
    USARTE0.DATA = data; // transmit ascii 3 over and over
	if(!(USARTE0.STATUS&USART_DREIF_bm))
		while(!(USARTE0.STATUS & USART_TXCIF_bm)); // wait for TX complete
  	USARTE0.STATUS |= USART_TXCIF_bm;  // clear TX interrupt flag
}
