/*
 * keyboard.c
 *
 * Created: 08/08/2023 10:06:51
 *  Author: Neeraj Adsul
 */ 

#include <xmega32a4u.h>
#include <usb_hid.h>
#include <stdint.h>
#include <stdio.h>
#include "delay.h"
#include "keyboard.h"

// Due to PCB Layout the keys are physically mapped as below.
char left_scanmap[N_ROWS][N_COLS] = {
	{KS_F6, KS_ESC, KS_F1, KS_F2, KS_F3, KS_F4, KS_F5},
	{KS_6_CARET, KS_GRAVE_ACCENT_TILDE, KS_1_EXCLAMATION, KS_2_AT, KS_3_HASHMARK, KS_4_DOLLAR, KS_5_PERCENTAGE},
	{KS_Y, KS_TAB, KS_Q, KS_W, KS_E, KS_R, KS_T},
	{KS_H, KS_CAPS_LOCK, KS_A, KS_S, KS_D, KS_F, KS_G},
	{KS_B, LEFT_SHIFT, KS_BACKSLASH_PIPE, KS_Z, KS_X, KS_C, KS_V},
	{KS_SPACE, NO_KEY, LEFT_CTRL, SPECIAL_KEY, FN_KEY, LEFT_ALT, LEFT_GUI},
};

char right_scanmap[N_ROWS][N_COLS] = {
	{KS_F7, KS_F8, KS_F9, KS_F10, KS_F11, KS_F12, KS_DELETE},
	{KS_7_AMPERSAND, KS_BACKSPACE, KS_EQUAL_PLUS, KS_MINUS_UNDERSCORE, KS_0_CLOSING_PARENS, KS_9_OPENING_PARENS, KS_8_ASTERISK},
	{KS_U, KS_ENTER, KS_CLOSING_BRACKET_BRACE, KS_OPENING_BRACKET_BRACE, KS_P, KS_O, KS_I},
	{KS_J, KS_ENTER, KS_3_HASHMARK, KS_APOSTROPHE_QUOTE, KS_SEMICOLON_COLON, KS_L, KS_K},
	{KS_N, RIGHT_SHIFT, KS_UP_ARROW, KS_SLASH_QUESTION_MARK, KS_DOT_GREATER_THAN, KS_COMMA_LESS_THAN, KS_M},
	{KS_SPACE, NO_KEY, KS_RIGHT_ARROW, KS_DOWN_ARROW, KS_LEFT_ARROW, RIGHT_ALT, RIGHT_GUI},
};

flash char * flash KEYNAMES[42] = {
	"F6", "Esc", "F1", "F2", "F3", "F4", "F5",
	"6^", "`¬", "1!", "2@", "3#", "4$", "5%",
	"Yy", "TB", "Qq", "Ww", "Ee", "Rr", "Tt",
	"Hh", "CP", "Aa", "Ss", "Dd", "Ff", "Gg",
	"Bb", "LS", "~|", "Zz", "Xx", "Cc", "Vv",
	"SP", "00", "LC", "mod", "Fn", "LA", "LG",
};


unsigned char keys[N_COLS] = {0};

volatile char key_buffer[N_KEYS_BUFFER] = {0};
volatile int key_buffer_index = 0;

uint8_t scan_keys(uint8_t left_or_right)
{
	uint8_t col_scan_mask = 0x01;
	//uint8_t row_pattern = 0;
	uint8_t ncol, nrow;
	uint8_t row_val =0;
	uint8_t keyevent = false;
	bit result;
	char somekey=0;
	
	
	// First Scan
	for (ncol=0 ; ncol < N_COLS ; ncol++)
	{
		COL_PORT.OUT = col_scan_mask << ncol;	
		row_val = ROW_PORT.IN & ROW_MASK;
		keys[ncol] = row_val;
	}		
	// Debounce Delay
	delay_ms(10);
	
	// Second scan after debounce delay
	for (ncol=0 ; ncol < N_COLS ; ncol++)
	{
		COL_PORT.OUT = col_scan_mask << ncol;	
		row_val = ROW_PORT.IN & ROW_MASK;
		if (row_val == 0 || keys[ncol] != row_val)
		{
			keys[ncol] = 0;
		} else {
			keyevent = true;
			for (nrow = 0; nrow < N_ROWS ; nrow++)
			{
				result = keys[ncol] & (1 << nrow);
				if (result == 1)
				{
					printf("%d %d %p\n", nrow, ncol, KEYNAMES[nrow*7 + ncol]);
				}
			}
		}
	}		
	
	return keyevent;
}


void log_keys()
{
	uint8_t ncol;
	for (ncol=0 ; ncol < N_COLS ; ncol++)
	{
		printf("%02x ", keys[ncol]);	
	}
	putchar('\n');
	
}

void show_scanmap(uint8_t left_or_right)
{
	uint8_t nrow, ncol;
	for (nrow=0;nrow<N_ROWS;nrow++)
	{
		for (ncol=0;ncol<N_COLS;ncol++)
		{
			if (left_or_right == LEFT_HALF)
			{
				printf("%02x ",left_scanmap[nrow][ncol]);
			} else {
				printf("%02x ",right_scanmap[nrow][ncol]);
			}
		}
		putchar('\n');
	}
}
