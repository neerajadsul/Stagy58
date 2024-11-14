#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>

#include "keymap.h"

char * LEFT[42] = {
	"Esc", "F1 ", "F2 ", "F3 ", "F4 ", "F5 ", "F6 ",
	"Btk", " 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 ",
	"Tab", " Q ", " W " , " E ", " R ", " T ", " Y ",
	"Tab", " A ", " S " , " D ", " F ", " G ", " H ",
	"Tab", " \\ ", " Z " , " X ", " C ", " V ", " B ",
	"---", "CTR", "Fun", "Opt", "Alt", "Mod", "Spc",
};

void init_set(Set_t *key_set)
{
	for (int i=0; i<SET_MAX_SIZE; i++)
	{
		key_set->buffer[i] = -1;
	}
	key_set->count = 0;
}

int add_to_set(Set_t *key_set, char key)
{
	if (key_set->count == SET_MAX_SIZE)
	{
		return 0;
	}
	for (int i=0; i< key_set->count; i++)
	{
		if (key_set->buffer[i] == key)
		{
			return 1;
		}
	}
	key_set->buffer[key_set->count] = key;
	key_set->count++; 
	return 1;
}


Set_t* keyboard_scan(Set_t* keymap)
{
	int KBD_COL_bm = 0x01;
	int KBD_ROWS_bm = 0x01;
	int key_seq_1d_arr = 0;
	
	for (int col=0; col < nCOLS; col++)
	{
		PORTC.OUT = KBD_COL_bm << col;
		for (int row=0; row < nROWS; row++)
		{
			_delay_ms(2);
			if (PORTD.IN & (KBD_ROWS_bm << row))
			{
				key_seq_1d_arr = row*(nROWS +1) + col  ;
				printf("C%d, R%d, K%d, %s > \n", col, row, key_seq_1d_arr, LEFT[key_seq_1d_arr]);
				add_to_set(keymap, key_seq_1d_arr);
			}
		}
	}
	return keymap;
}

char* get_key_id(int key)
{
	return LEFT[key];
}