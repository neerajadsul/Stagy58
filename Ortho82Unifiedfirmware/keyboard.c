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
	{KS_B, KM_LEFT_SHIFT, KS_BACKSLASH_PIPE, KS_V, KS_X, KS_C, KS_Z},
	{KS_SPACE, NO_KEY, KM_LEFT_CTRL, MOD_KEY, FN_KEY, KM_LEFT_ALT, KM_LEFT_GUI},
};

unsigned char keys[N_COLS] = {0};

char key_buffer[N_KEYS_BUFFER];
volatile uint8_t key_buffer_index = 0;

uint8_t scan_keys()
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
	
	// Seconds scan after debounce delay
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
					somekey = left_scanmap[nrow][ncol];
					printf("%02x %d %d \n", somekey, nrow, ncol);
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

void show_scanmap()
{
	uint8_t nrow, ncol;
	
	for (nrow=0;nrow<N_ROWS;nrow++)
	{
		for (ncol=0;ncol<N_COLS;ncol++)
		{
			printf("%02x ",left_scanmap[nrow][ncol]);
		}
		putchar('\n');
	}
}
