/*******************************************************
USARTs initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator
� Copyright 1998-2019 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : SplitKeyboardPS2
*******************************************************/

// I/O Registers definitions
#include <xmega32a4u.h>

// USARTs initialization functions
#include "usarts_init.h"

// Disable an USART
void usart_disable(USART_t *pu)
{
// Rx and Tx are off
pu->CTRLB=0;
// Ensure that all interrupts generated by the USART are off
pu->CTRLA=0;
}

// USARTE0 initialization
void usarte0_init(void)
{
// Note: The correct PORTE direction for the RxD, TxD and XCK signals
// is configured in the ports_init function.

// Transmitter is enabled
// Set TxD=1
PORTE.OUTSET=0x08;

// Communication mode: Asynchronous USART
// Data bits: 8
// Stop bits: 1
// Parity: Disabled
USARTE0.CTRLC=USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_CHSIZE_8BIT_gc;

// Receive complete interrupt: Low Level
// Transmit complete interrupt: Low Level
// Data register empty interrupt: Disabled
USARTE0.CTRLA=(USARTE0.CTRLA & (~(USART_RXCINTLVL_gm | USART_TXCINTLVL_gm | USART_DREINTLVL_gm))) |
	USART_RXCINTLVL_LO_gc | USART_TXCINTLVL_LO_gc | USART_DREINTLVL_OFF_gc;

// Required Baud rate: 115200
// Real Baud Rate: 115211.5 (x2 Mode), Error: 0.0 %
USARTE0.BAUDCTRLA=0x85;
USARTE0.BAUDCTRLB=((0x09 << USART_BSCALE_gp) & USART_BSCALE_gm) | 0x0C;

// Receiver: On
// Transmitter: On
// Double transmission speed mode: On
// Multi-processor communication mode: Off
USARTE0.CTRLB=(USARTE0.CTRLB & (~(USART_RXEN_bm | USART_TXEN_bm | USART_CLK2X_bm | USART_MPCM_bm | USART_TXB8_bm))) |
	USART_RXEN_bm | USART_TXEN_bm | USART_CLK2X_bm;
}

// Note: RX_BUFFER_SIZE_USARTE0 is #define-d in 'usarts_init.h' with the value 8
char rx_buffer_usarte0[RX_BUFFER_SIZE_USARTE0];

#if RX_BUFFER_SIZE_USARTE0 <= 256
volatile unsigned char rx_wr_index_usarte0=0,rx_rd_index_usarte0=0;
#else
volatile unsigned int rx_wr_index_usarte0=0,rx_rd_index_usarte0=0;
#endif

#if RX_BUFFER_SIZE_USARTE0 < 256
volatile unsigned char rx_counter_usarte0=0;
#else
volatile unsigned int rx_counter_usarte0=0;
#endif

// This flag is set on USARTE0 Receiver buffer overflow
bit rx_buffer_overflow_usarte0=0;

// USARTE0 Receiver interrupt service routine
interrupt [USARTE0_RXC_vect] void usarte0_rx_isr(void)
{
unsigned char status;
char data;

status=USARTE0.STATUS;
data=USARTE0.DATA;
if ((status & (USART_FERR_bm | USART_PERR_bm | USART_BUFOVF_bm)) == 0)
   {
   rx_buffer_usarte0[rx_wr_index_usarte0++]=data;
#if RX_BUFFER_SIZE_USARTE0 == 256
   // special case for receiver buffer size=256
   if (++rx_counter_usarte0 == 0) rx_buffer_overflow_usarte0=1;
#else
   if (rx_wr_index_usarte0 == RX_BUFFER_SIZE_USARTE0) rx_wr_index_usarte0=0;
   if (++rx_counter_usarte0 == RX_BUFFER_SIZE_USARTE0)
      {
      rx_counter_usarte0=0;
      rx_buffer_overflow_usarte0=1;
      }
#endif
   }
}

// Receive a character from USARTE0
// USARTE0 is used as the default input device by the 'getchar' function
// #define _ALTERNATE_GETCHAR_ is inserted for this purpose
// in the main program source file before #include <stdio.h>
#pragma used+
char getchar(void)
{
char data;

while (rx_counter_usarte0==0);
data=rx_buffer_usarte0[rx_rd_index_usarte0++];
#if RX_BUFFER_SIZE_USARTE0 != 256
if (rx_rd_index_usarte0 == RX_BUFFER_SIZE_USARTE0) rx_rd_index_usarte0=0;
#endif
#asm("cli")
--rx_counter_usarte0;
#asm("sei")
return data;
}
#pragma used-

// Note: TX_BUFFER_SIZE_USARTE0 is #define-d in 'usarts_init.h' with the value 8
char tx_buffer_usarte0[TX_BUFFER_SIZE_USARTE0];

#if TX_BUFFER_SIZE_USARTE0 <= 256
volatile unsigned char tx_wr_index_usarte0=0,tx_rd_index_usarte0=0;
#else
volatile unsigned int tx_wr_index_usarte0=0,tx_rd_index_usarte0=0;
#endif

#if TX_BUFFER_SIZE_USARTE0 < 256
volatile unsigned char tx_counter_usarte0=0;
#else
volatile unsigned int tx_counter_usarte0=0;
#endif

// USARTE0 Transmitter interrupt service routine
interrupt [USARTE0_TXC_vect] void usarte0_tx_isr(void)
{
if (tx_counter_usarte0)
   {
   --tx_counter_usarte0;
   USARTE0.DATA=tx_buffer_usarte0[tx_rd_index_usarte0++];
#if TX_BUFFER_SIZE_USARTE0 != 256
   if (tx_rd_index_usarte0 == TX_BUFFER_SIZE_USARTE0) tx_rd_index_usarte0=0;
#endif
   }
}

// Write a character to the USARTE0 Transmitter buffer
// USARTE0 is used as the default output device by the 'putchar' function
// #define _ALTERNATE_PUTCHAR_ is inserted for this purpose
// in the main program source file before #include <stdio.h>
#pragma used+
void putchar(char c)
{
while (tx_counter_usarte0 == TX_BUFFER_SIZE_USARTE0);
#asm("cli")
if (tx_counter_usarte0 || ((USARTE0.STATUS & USART_DREIF_bm)==0))
   {
   tx_buffer_usarte0[tx_wr_index_usarte0++]=c;
#if TX_BUFFER_SIZE_USARTE0 != 256
   if (tx_wr_index_usarte0 == TX_BUFFER_SIZE_USARTE0) tx_wr_index_usarte0=0;
#endif
   ++tx_counter_usarte0;
   }
else
   USARTE0.DATA=c;
#asm("sei")
}
#pragma used-

