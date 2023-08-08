/*
 * keyboard.c
 *
 * Created: 08/08/2023 10:06:51
 *  Author: Neeraj Adsul
 */ 


#include <usb_hid.h>
#include <stdint.h>
#include "keyboard.h"

char left_scanmap[N_ROWS][N_COLS] = {
	{KS_ESC, KS_F1, KS_F2, KS_F3, KS_F4, KS_F5, KS_F6},
	{KS_GRAVE_ACCENT_TILDE, KS_1_EXCLAMATION, KS_2_AT, KS_3_HASHMARK, KS_4_DOLLAR, KS_5_PERCENTAGE, KS_6_CARET},
	{KS_TAB, KS_Q, KS_W, KS_E, KS_R, KS_T, KS_Y},
	{KS_CAPS_LOCK, KS_A, KS_S, KS_D, KS_F, KS_G, KS_H},
	{KM_LEFT_SHIFT, KS_BACKSLASH_PIPE, KS_Z, KS_X, KS_C, KS_V, KS_B},
	{NO_KEY, KM_LEFT_CTRL, MOD_KEY, FN_KEY, KM_LEFT_ALT, KM_LEFT_GUI, KS_SPACE},
};


void scan_keys()
{
	uint8_t col_scan_mask = 0x01;
	uint8_t row_pattern = 0;
	
	
	
}
