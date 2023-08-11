// #include <avr/io.h>
// #include <interrupt.h>

// #include "usart.h"


// int usart_init(void)
// {  
//     // Set PE3 as output
//     // PORTE_DIRSET = 0x08;
//     PORTE_DIR = 0x08;
//     // Set TXD High
//     PORTE_OUTSET = 0x08;

//     // Communication mode: Asynchronous USART
//     // Data bits: 8
//     // Stop bits: 1
//     // Parity: Disabled
//     USARTE0_CTRLC = USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_CHSIZE_8BIT_gc;

//     // USARTE0.BAUDCTRLA = (2094 & 0xff) << USART_BSEL_gp;
//     // USARTE0.BAUDCTRLB = ((-7) << USART_BSCALE_gp) | ((2094 >> 8) << USART_BSEL_gp);
//     // USARTE0.BAUDCTRLA = (3205 & 0xff) << USART_BSEL_gp;
//     USARTE0.BAUDCTRLB = ((-7) << USART_BSCALE_gp) | ((3205 >> 8) << USART_BSEL_gp);

//     // Receive and Transmit Interrupt
//     USARTE0_CTRLA = USART_RXCINTLVL0_bm | USART_TXCINTLVL0_bm;

//     // Enable Receiver and Transmitter, Double Baudrate
//     USARTE0_CTRLB = USART_RXEN_bm | USART_TXEN_bm | USART_CLK2X_bm;
// }


// uint8_t sendchar(uint8_t ch)
// {
//     while (!(USARTE0_STATUS & USART_DREIF_bm));
//     USARTE0_DATA = ch;
// }

// ISR(USARTE0_TXC_vect)
// {
// }
