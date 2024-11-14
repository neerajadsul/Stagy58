#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>

#include "keymap.h"

int main(void)
{
	/* Initializes MCU, drivers and Middleware */
	atmel_start_init();
	//int row=0, col=0;
	static Set_t keymap;
	init_set(&keymap);
	/* Replace with your application code */
	while (1) {
		keyboard_scan(&keymap);
		for (int i=0; i < keymap.count; i++)
		{
			printf("%s\n", get_key_id(keymap.buffer[i]));
		}
		init_set(&keymap);
		_delay_ms(20);
		USER_LED_toggle_level();
	}
}
