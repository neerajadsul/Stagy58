#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>

#include "keymap.h"


int main(void)
{
	/* Initializes MCU, drivers and Middleware */
	atmel_start_init();
	//int row=0, col=0;
	static Set_t prev_keymap;
	init_set(&prev_keymap);
	static Set_t curr_keymap;
	init_set(&curr_keymap);
	/* Replace with your application code */
	//TODO: Need to implement key down and up state machine.
	while (1) {
		keyboard_scan(&curr_keymap);
		for (int i=0; i < curr_keymap.count; i++)
		{	
			// Currently pressed keys
			int key = curr_keymap.buffer[i];
			if (key < 42 && key >= 0)
			{
				printf("Pressed %s\n", get_key_id(key));
			}
			
		}
		for (int i=0; i<prev_keymap.count ; i++)
		{
			// Released keys as they were previously pressed but not anymore
			int key = prev_keymap.buffer[i];
			if (is_in_set(&curr_keymap, key))
			{
				printf("Released %s\n", get_key_id(key));
			}
		}
		copy_set(&curr_keymap, &prev_keymap);
		init_set(&curr_keymap);
		//_delay_ms(10);
		USER_LED_toggle_level();
	}
}
