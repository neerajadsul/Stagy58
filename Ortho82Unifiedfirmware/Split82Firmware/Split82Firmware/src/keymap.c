#include <atmel_start.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>

#include "keymap.h"
#include "keycodes.h"

#define MOD_LEFT	0x71
#define MOD_RIGHT	0x72
#define FN_KEY		0x73

char* LEFT_KEYS[42] = {
	"Es", "F1", "F2", "F3", "F4", "F5", "F6",
	"`¬", "1!", "2\"", "3£", "4$", "5%", "6^",
	"Tb", "Qq", "Ww" , "Ee", "Rr", "Tt", "Yy",
	"Cp", "Aa", "Ss" , "Dd", "Ff", "Gg", "Hh",
	"LS", "\\|", "Zz" , "Xx", "Cc", "Vv", "Bb",
	"--", "CT", "Fn", "Op", "At", "ML", "Sp",
};

//uint8_t LEFT_CODE[42] = {
	//ESC, F1, F2, F3, F4, F5, F6,
	//TILDE, ONE, TWO, THREE, FOUR, FIVE, SIX,
	//TAB, Q, W, E, R, T, Y,
	//CAPS_LOCK, A, S , D, F, G, H,
	//LEFT_SHIFT, BACKSLASH, Z, X, C, V, B,
	//0x00, LEFT_CTRL, FN_KEY, LEFT_GUI , LEFT_ALT, MOD_LEFT, SPACE,
//};

char* RIGHT_KEYS[42] = {
	"DL", "12", "11", "10", "F9", "F8", "F7",
	"Bk", "=+", "-_", "0)", "9(", "8*", "7&",
	"LF", "]}", "[{" , "Pp", "Oo", "Ii", "Uu",
	"LF", "#~", "'@" , ";:", "Ll", "Kk", "Jj",
	"RS", "Up", "/?" , ".>", ",<", "Mm", "Nn",
	"--", "Rt", "Dw", "Lt", "At", "Op", "Sp"
};


void init_set(Keys_t *key_set)
{
	for (int i=0; i<SET_MAX_SIZE; i++)
	{
		key_set->keys[i] = -1;
	}
	key_set->count = 0;
}

int add_to_set(Keys_t *key_set, char key)
{
	if (key_set->count == SET_MAX_SIZE)
	{
		return 0;
	}
	for (int i=0; i< key_set->count; i++)
	{
		if (key_set->keys[i] == key)
		{
			return 1;
		}
	}
	key_set->keys[key_set->count] = key;
	key_set->count++; 
	return 1;
}

void copy_set(Keys_t* src_keymap, Keys_t* dest_keymap)
{
	for (int i=0; i< src_keymap->count; i++)
	{
		add_to_set(dest_keymap, src_keymap->keys[i]);
	}
	
		
}

bool is_in_set(Keys_t* keymap, int key)
{
	for (int i=0; i < keymap->count; i++)
	{
		if (key == keymap->keys[i])
			return true;
	}
	return false;
}

Keys_t* keyboard_scan(Keys_t* keymap)
{
	int KBD_COL_bm = 0x01;
	int KBD_ROWS_bm = 0x01;
	int key_seq_1d_arr = 0;
	
	for (int col=0; col < nCOLS; col++)
	{
		PORTC.OUT = KBD_COL_bm << col;
		_delay_ms(SCAN_DELAY);
		for (int row=0; row < nROWS; row++)
		{
			_delay_ms(SCAN_DELAY);
			if (PORTD.IN & (KBD_ROWS_bm << row))
			{
				key_seq_1d_arr = row*(nROWS +1) + col  ;
				//printf("C%d, R%d, K%d, %s > \n", col, row, key_seq_1d_arr, LEFT[key_seq_1d_arr]);
				add_to_set(keymap, key_seq_1d_arr);
			}
		}
	}
	return keymap;
}

char* get_key_id(int key, int is_left)
{
	if (is_left)
		return LEFT_KEYS[key];
	return RIGHT_KEYS[key];
}

//uint8_t get_key_code(int key, int is_left)
//{
	//if (is_left)
		//return LEFT_CODE[key];
	//return LEFT_CODE[key];
//}

bool is_modifier(uint8_t key)
{
	switch(key) {
		case 28:
		case 36:
		case 38:
		case 39:
			return true;
		default:
			return false;
	}
}