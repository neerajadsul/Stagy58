#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>

#include "keymap.h"
#include "keycodes.h"
#include "version.h"

#define PRESSED		'P'
#define RELEASED	'R'


typedef struct {
	uint8_t key;
	uint8_t event;	
} Event_t;

void send_key_event(uint8_t key, uint8_t event);
int receive_key_event(Event_t* event);
void test_sequence();
void send_keys(HID_Keys_t*, char);
void init_keyboard_zeros(void);


void send_pressed_events(Keys_t *curr_keymap, HID_Keys_t *hid_keys, Keys_t prev_keymap, uint8_t is_left_half)
{
	for (uint8_t i=0; i < curr_keymap->count; i++) {	
		// Currently pressed keys
		uint8_t key = curr_keymap->keys[i];
		//uint8_t code;
		hid_keys->keys[i] = 0x00;
		if (!is_in_set(&prev_keymap, key)) {
			printf("%c 1 %d %s\n", is_left_half ? 'L':'R', key, get_key_id(key, is_left_half));
			USER_LED_toggle_level();
			send_key_event(key, PRESSED);
		}
	}
	
}

void send_released_events(Keys_t *prev_keymap, HID_Keys_t *hid_keys, Keys_t curr_keymap, uint8_t is_left_half)
{
	for (uint8_t i=0; i<prev_keymap->count ; i++)
	{
		// Released keys as they were previously pressed but not anymore
		uint8_t key = prev_keymap->keys[i];
		//uint8_t code;
		if (!is_in_set(&curr_keymap, key))
		{
			printf("%c 0 %d %s\n", is_left_half ? 'L':'R', key, get_key_id(key, is_left_half));
			USER_LED_toggle_level();
			send_key_event(key, RELEASED);
		}
	}
}

#define START_OF_FRAME	'<'
#define END_OF_FRAME	'>'
#define FRAME_SEPARATOR	':'
#define EOL	'\n'

void process_other_half_events()
{
	uint8_t packet_len = 0;
	char ch = 0;
	while (ch != EOL) {
		ch = USART_KBD_read();
		switch (ch) {
			case START_OF_FRAME:
			break;
			case FRAME_SEPARATOR:
			break;
			case END_OF_FRAME:
			break;
			case EOL:
			break;
			default:
			break;
		}
	}
		
	
}

int main(void)
{
	/* Initializes MCU, drivers and Middleware */
	PORTE.OUTSET = PIN3_bm;
	_delay_ms(100);
	atmel_start_init();
	// Send firmware version
	printf("Version: %s\n", get_semantic_version());
	static Keys_t prev_keymap;
	init_set(&prev_keymap);
	static Keys_t curr_keymap;
	uint8_t is_left_half = IS_LEFT_get_level() ? 0 : 1;
	HID_Keys_t hid_keys = {.modifier=0x00, .keys={0,0,0,0,0,0}};
	printf("Is Left Half %d", is_left_half);
	_delay_ms(500);
	while (1) {
		init_set(&curr_keymap);
		keyboard_scan(&curr_keymap);
		send_pressed_events(&curr_keymap, &hid_keys, prev_keymap, is_left_half);
		send_released_events(&prev_keymap, &hid_keys, curr_keymap, is_left_half);
		init_set(&prev_keymap);
		copy_set(&curr_keymap, &prev_keymap);
		if (is_left_half) {
			process_other_half_events();
		}
	}
}


void send_key_event(uint8_t key, uint8_t event)
{
	USART_KBD_write('<');
	_delay_ms(1);
	USART_KBD_write('0' + (uint8_t)key/10);
	_delay_ms(1);
	USART_KBD_write('0' + key%10);
	_delay_ms(1);
	USART_KBD_write(':');
	_delay_ms(1);
	if (event == PRESSED) {
		USART_KBD_write('1');
	} 
	else {
		USART_KBD_write('0');
	}
	_delay_ms(1);
	USART_KBD_write('>');
	_delay_ms(1);
	USART_KBD_write('\n');
	_delay_ms(1);
}

