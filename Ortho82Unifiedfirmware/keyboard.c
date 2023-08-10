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

typedef enum rowid {
	ALL_ROWS=0,
	ROW_FUN=1<<0,
	ROW_NUMBERS=1<<1,
	ROW_TAB=1<<2,
	ROW_CAPS=1<<3,
	ROW_SHIFT=1<<4,
	ROW_SPACE=1<<5,
}row_id;

// Due to PCB Layout the keys are physically mapped as below.
char left_scanmap[N_ROWS][N_COLS] = {
	{KS_F6, KS_ESC, KS_F1, KS_F2, KS_F3, KS_F4, KS_F5},
	{KS_6_CARET, KS_GRAVE_ACCENT_TILDE, KS_1_EXCLAMATION, KS_2_AT, KS_3_HASHMARK, KS_4_DOLLAR, KS_5_PERCENTAGE},
	{KS_Y, KS_TAB, KS_Q, KS_W, KS_E, KS_R, KS_T},
	{KS_H, KS_CAPS_LOCK, KS_A, KS_S, KS_D, KS_F, KS_G},
	{KS_B, KS_LEFT_SHIFT, KS_BACKSLASH_PIPE, KS_Z, KS_X, KS_C, KS_V},
	{KS_SPACE, NO_KEY, KS_LEFT_CTRL, SPECIAL_KEY, FN_KEY, KS_LEFT_ALT, KS_LEFT_GUI},
};

char right_scanmap[N_ROWS][N_COLS] = {
	{KS_F7, KS_F8, KS_F9, KS_F10, KS_F11, KS_F12, KS_DELETE},
	{KS_7_AMPERSAND, KS_BACKSPACE, KS_EQUAL_PLUS, KS_MINUS_UNDERSCORE, KS_0_CLOSING_PARENS, KS_9_OPENING_PARENS, KS_8_ASTERISK},
	{KS_U, KS_ENTER, KS_CLOSING_BRACKET_BRACE, KS_OPENING_BRACKET_BRACE, KS_P, KS_O, KS_I},
	{KS_J, KS_ENTER, KS_3_HASHMARK, KS_APOSTROPHE_QUOTE, KS_SEMICOLON_COLON, KS_L, KS_K},
	{KS_N, KS_RIGHT_SHIFT, KS_UP_ARROW, KS_SLASH_QUESTION_MARK, KS_DOT_GREATER_THAN, KS_COMMA_LESS_THAN, KS_M},
	{KS_SPACE, NO_KEY, KS_RIGHT_ARROW, KS_DOWN_ARROW, KS_LEFT_ARROW, KS_RIGHT_ALT, KS_RIGHT_GUI},
};

flash char * flash KEYNAMES[42] = {
	"F6", "Esc", "F1", "F2", "F3", "F4", "F5",
	"6^", "`¬", "1!", "2@", "3#", "4$", "5%",
	"Yy", "TB", "Qq", "Ww", "Ee", "Rr", "Tt",
	"Hh", "CP", "Aa", "Ss", "Dd", "Ff", "Gg",
	"Bb", "LS", "~|", "Zz", "Xx", "Cc", "Vv",
	"SP", "00", "LC", "mod", "Fn", "LA", "LG",
};

volatile uint8_t debounce_matrix[N_ROWS][N_COLS] = {0};

volatile char curr_keys[N_COLS] = {0};
//volatile char prev_keys[N_COLS] = {0};
//volatile char next_keys[N_COLS] = {0};


volatile char key_buffer[N_KEYS_BUFFER] = {0};
volatile int key_buffer_index = 0;

void update_curr_keys()
{
	uint8_t ncol;
	uint8_t COL_SCAN_bm = 0x01;
	uint8_t row_val;
	
	for (ncol=0 ; ncol < N_COLS ; ncol++)
	{
		COL_PORT.OUT = COL_SCAN_bm << ncol;
		row_val = ROW_PORT.IN & ROW_MASK;
		curr_keys[ncol] = row_val;
	}	
}

void update_debounce_matrix()
{
	uint8_t nrow, ncol;	
	for (ncol=0 ; ncol < N_COLS ; ncol++)
	{
		for (nrow=0 ; nrow < N_ROWS ; nrow++)
		{
			if (curr_keys[ncol] & (1<<nrow))
			{
				debounce_matrix[nrow][ncol] += 1;
			} else {
				debounce_matrix[nrow][ncol] = 0;
			}
		}
	}
}




uint8_t report_debounced_keys()
{
	uint8_t nrow, ncol, numkeys=0;	
	for (ncol=0 ; ncol < N_COLS ; ncol++)
	{
		for (nrow=0 ; nrow < N_ROWS ; nrow++)
		{
			if (debounce_matrix[nrow][ncol] > 50) {
				//printf("%d %d %p\n", nrow, ncol, KEYNAMES[nrow*7 + ncol]);
				add_key_buffer(left_scanmap[nrow][ncol]);
				numkeys++;
				debounce_matrix[nrow][ncol] = 0;
			} 
			//else if (debounce_matrix[nrow][ncol] == 0) {
				//remove_key_buffer(left_scanmap[nrow][ncol]);
			//}
		}
	}
	return numkeys;
}

void add_key_buffer(uint8_t key)
{
	uint8_t idx;
	for (idx=0 ; idx < N_KEYS_BUFFER ; idx++)
	{
		if (key_buffer[idx] == key)
		{
			return;
		}
	}
	if (key_buffer_index >= N_KEYS_BUFFER)
	{
		return;
	} else {
		key_buffer[key_buffer_index++] = key;
	}
}

void remove_key_buffer(char key)
{
	uint8_t idx, remove_idx;
	
	// Find matching key in key_buffer and record its index
	for (idx=0 ; idx < N_KEYS_BUFFER ; idx++)
	{
		if (key_buffer[idx] == key)
		{
			remove_idx = idx;
			key_buffer[idx] = 0;
			key_buffer_index--;
			break;
		}
	}
	if (remove_idx > 0)
	{
		// Shift data from remove index by 1
		for (idx=remove_idx; idx < (N_KEYS_BUFFER-1) ; idx++)
		{
			key_buffer[idx] = key_buffer[idx+1];
		}
		
	}
	
}

void log_keys()
{
	uint8_t ncol;
	for (ncol=0 ; ncol < N_COLS ; ncol++)
	{
		printf("%02x ", curr_keys[ncol]);	
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
