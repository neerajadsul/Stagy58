/*
 * keyboard.h
 *
 * Created: 08/08/2023 10:07:09
 *  Author: Neeraj Adsul
 */ 


#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#define N_KEYS_BUFFER	6
#define N_COLS	7
#define N_ROWS	6
#define NO_KEY	0
#define FN_KEY	0
#define MOD_KEY	0

#define LEFT_HALF	0
#define RIGHT_HALF	1

#define ROW_PORT	PORTD
#define COL_PORT	PORTC
#define LEFT_RIGHT_PORT	PORTB
#define LEFT_RIGHT_PIN_bm	0x04

#define LED_ON	(PORTB.OUTCLR = 1 << 3)
#define LED_OFF	(PORTB.OUTSET = 1 << 3)

#define ROW_MASK	0b00111111

uint8_t scan_keys(uint8_t);
void log_keys();
void show_scanmap(uint8_t);


#endif /* KEYBOARD_H_ */