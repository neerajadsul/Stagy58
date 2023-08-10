/*
 * keyboard.h
 *
 * Created: 08/08/2023 10:07:09
 *  Author: Neeraj Adsul
 */ 


#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#define ROW_FUN_bm		0x01
#define ROW_NUMBERS_bm	0x02
#define ROW_TAB_bm		0x04
#define ROW_CAPS_bm	0x08
#define ROW_SHIFT_bm	0x10
#define ROW_SPACE_bm	0x20

#define COL_ESC_DEL		1 << 1
#define COL_F1_EQUAL	1 << 2
#define COL_F2_MINUS	1 << 3
#define COL_F3_0		1 << 4
#define COL_F4_9		1 << 5
#define COL_F5_8		1 << 6
#define COL_F6_7		1 << 0

#define N_KEYS_BUFFER	8
#define N_COLS	7
#define N_ROWS	6
#define NO_KEY	0
#define FN_KEY	0xFA
#define SPECIAL_KEY	0xFB

#define LEFT_CTRL	0xF1
#define LEFT_ALT	0xF2
#define LEFT_GUI	0xF3
#define LEFT_SHIFT	0xF4

#define RIGHT_CTRL	0xF5
#define RIGHT_ALT	0xF6
#define RIGHT_GUI	0xF7
#define RIGHT_SHIFT	0xF8

#define LEFT_HALF	0
#define RIGHT_HALF	1

#define ROW_PORT	PORTD
#define COL_PORT	PORTC
#define LEFT_RIGHT_PORT	PORTB
#define LEFT_RIGHT_PIN_bm	0x04

#define LED_ON	(PORTB.OUTCLR = 1 << 3)
#define LED_OFF	(PORTB.OUTSET = 1 << 3)

#define COL_MASK	0b01111111
#define ROW_MASK	0b00111111
#define READ_ROW_INPUT	(PORTD.IN & ROW_MASK)

void log_keys();
void show_scanmap(uint8_t);
void update_curr_keys();
void update_debounce_matrix();
uint8_t report_debounced_keys();
void add_key_buffer(uint8_t);
void remove_key_buffer(char);


#endif /* KEYBOARD_H_ */