#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>

#include "keymap.h"
#include "version.h"


int main(void)
{
	/* Initializes MCU, drivers and Middleware */
	atmel_start_init();
	// Send firmware version
	printf("Version: %s\n", get_semantic_version());
	//int row=0, col=0;
	static Keys_t prev_keymap;
	init_set(&prev_keymap);
	static Keys_t curr_keymap;
	while (1) {
		init_set(&curr_keymap);
		keyboard_scan(&curr_keymap);
		for (int i=0; i < curr_keymap.count; i++)
		{	
			// Currently pressed keys
			int key = curr_keymap.keys[i];
			if (!is_in_set(&prev_keymap, key))
			{
				printf("Pressed %s\n", get_key_id(key));
				USER_LED_toggle_level();
			}			
		}
		for (int i=0; i<prev_keymap.count ; i++)
		{
			// Released keys as they were previously pressed but not anymore
			int key = prev_keymap.keys[i];
			if (!is_in_set(&curr_keymap, key))
			{
				printf("Released %s\n", get_key_id(key));
				USER_LED_toggle_level();
			}
		}
		init_set(&prev_keymap);
		copy_set(&curr_keymap, &prev_keymap);
	}
}
