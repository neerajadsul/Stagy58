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

#define ROW_MASK	0b00111111

uint8_t scan_keys();
void log_keys();
void show_scanmap();


#endif /* KEYBOARD_H_ */