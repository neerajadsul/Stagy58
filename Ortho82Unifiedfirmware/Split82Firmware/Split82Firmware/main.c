#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>

#define nROWS 6
#define nCOLS 7

int keyboard_scan();

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	//int row=0, col=0;
	/* Replace with your application code */
	while (1) {
		keyboard_scan();
		_delay_ms(1000);
		USER_LED_toggle_level();
		//printf("Col:%d Row:%d\n", row, col);
	}
}

int keyboard_scan()
{	
	int KBD_COL_bm = 0b01111111;
	int KBD_ROWS_bm = 0b00111111;
	
	int row_reading = 0x00;
	for (int col=0; col < nCOLS; col++)
	{
		PORTC.OUT = KBD_COL_bm & (0x01 << col);
		_delay_ms(10);
		row_reading = PORTD.IN & KBD_ROWS_bm;
		printf("%d, %d\n", col, row_reading);
	}
	return 0;
}