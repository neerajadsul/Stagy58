/*******************************************************
USARTs initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator
Copyright: Neeraj Adsul <neeraj.adsul[at]gmail.com>

Project : Ortho82UnifiedKeyboard
*******************************************************/

#ifndef _USARTS_INIT_INCLUDED_
#define _USARTS_INIT_INCLUDED_

// Disable an USART
void usart_disable(USART_t *pu);
// USARTE0 is used as the default input device by the 'getchar' function
// #define _ALTERNATE_GETCHAR_ is inserted for this purpose
// in the main program source file before #include <stdio.h>
char getchar(void);
// USARTE0 is used as the default output device by the 'putchar' function
// #define _ALTERNATE_PUTCHAR_ is inserted for this purpose
// in the main program source file before #include <stdio.h>
void putchar(char c);
// USARTE0 initialization
void usarte0_init(void);
// USARTE0 Receiver buffer
#define RX_BUFFER_SIZE_USARTE0 16
extern char rx_buffer_usarte0[RX_BUFFER_SIZE_USARTE0];

#if RX_BUFFER_SIZE_USARTE0 <= 256
extern volatile unsigned char rx_wr_index_usarte0,rx_rd_index_usarte0;
#else
extern volatile unsigned int rx_wr_index_usarte0,rx_rd_index_usarte0;
#endif

#if RX_BUFFER_SIZE_USARTE0 < 256
extern volatile unsigned char rx_counter_usarte0;
#else
extern volatile unsigned int rx_counter_usarte0;
#endif

// This flag is set on USARTE0 Receiver buffer overflow
extern bit rx_buffer_overflow_usarte0;
// USARTE0 Transmitter buffer
#define TX_BUFFER_SIZE_USARTE0 16
extern char tx_buffer_usarte0[TX_BUFFER_SIZE_USARTE0];

#if TX_BUFFER_SIZE_USARTE0 <= 256
extern volatile unsigned char tx_wr_index_usarte0,tx_rd_index_usarte0;
#else
extern volatile unsigned int tx_wr_index_usarte0,tx_rd_index_usarte0;
#endif

#if TX_BUFFER_SIZE_USARTE0 < 256
extern volatile unsigned char tx_counter_usarte0;
#else
extern volatile unsigned int tx_counter_usarte0;
#endif

#endif
