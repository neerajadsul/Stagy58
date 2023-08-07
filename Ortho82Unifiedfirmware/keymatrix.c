/*
 * keymatrix.c
 *
 *  Author: Neeraj Adsul
 */ 

#include <stdint.h>
#include "keymatrix.h"


// Column scan bitmask
uint8_t columns = 0x01;
// Row scan result
uint8_t rows = 0x00;
// Keys currently pressed

/** Scan keys matrix and return currently pressed keys.
*  Maximum 6 keys are returned at a time.
*/
char* scan_keys()
{
	char keys[6] = {0};
	
}
