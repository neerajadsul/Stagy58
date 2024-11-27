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
void send_keys(HID_Keys_t*);
bool is_modifier(uint8_t);
void init_keyboard_zeros(void);


int main(void)
{
	/* Initializes MCU, drivers and Middleware */
	PORTE.OUTSET = PIN3_bm;
	_delay_ms(100);
	atmel_start_init();
	// Send firmware version
	//printf("Version: %s\n", get_semantic_version());
	//int row=0, col=0;
	static Keys_t prev_keymap;
	init_set(&prev_keymap);
	static Keys_t curr_keymap;
	static Event_t key_event;
	uint8_t is_left_half = IS_LEFT_get_level() ? 0 : 1;
	HID_Keys_t empty_keys = {.modifier=0x00, .keys={0,0,0,0,0,0}};
	HID_Keys_t hid_keys = {.modifier=0x00, .keys={0,0,0,0,0,0}};
	//printf("Is Left Half %d", is_left_half);
	bool is_key_to_send=false;
	//while(USART_0_is_rx_ready()) USART_0_read();
	_delay_ms(1500);
	//init_keyboard_zeros();
	//while(1){};
	while (1) {
		init_set(&curr_keymap);
		keyboard_scan(&curr_keymap);
		for (uint8_t i=0; i < curr_keymap.count; i++)
		{	
			// Currently pressed keys
			uint8_t key = curr_keymap.keys[i];
			uint8_t code;
			hid_keys.keys[i] = 0x00;
			if (!is_in_set(&prev_keymap, key))
			{
				printf("%c 1 %s\n", is_left_half ? 'L':'R', get_key_id(key, is_left_half));
				//send_alt_tab();
				 code = get_key_code(key, is_left_half);
				if (is_modifier(code))
				{
					hid_keys.modifier = code | hid_keys.modifier;
				} 
				else
				{
					hid_keys.keys[i] = code;
				}
				USER_LED_toggle_level();
				send_key_event(key, PRESSED);
			}			
		}
				is_key_to_send = false;
		for (uint8_t i=0; i<prev_keymap.count ; i++)
		{
			// Released keys as they were previously pressed but not anymore
			uint8_t key = prev_keymap.keys[i];
			hid_keys.keys[i] = 0x00;
			if (!is_in_set(&curr_keymap, key))
			{
				printf("%c 0 %s\n", is_left_half ? 'L':'R', get_key_id(key, is_left_half));
				USER_LED_toggle_level();
				send_key_event(key, RELEASED);
			}
		}
		init_set(&prev_keymap);
		copy_set(&curr_keymap, &prev_keymap);
		if (is_left_half)
		{
			key_event.key = 0;
			key_event.event = 0;

			if (receive_key_event(&key_event))
			{
				printf("%c %c %s\n", is_left_half ? 'L':'R', key_event.event, get_key_id(key_event.key, is_left_half));
			}
		}
		
	}
}


void send_key_event(uint8_t key, uint8_t event)
{
	USART_KBD_write('0' + (uint8_t)key/10);
	USART_KBD_write('0' + key%10);
	USART_KBD_write(':');
	USART_KBD_write(event);
	USART_KBD_write('\n');
}

void send_keys(HID_Keys_t *keys)
{
	USART_USB_write(keys->modifier);
	USART_KBD_write(keys->modifier);
	USART_USB_write(0x00);
	USART_KBD_write(0x00);
	for (uint8_t i=0; i < 6; i++)
	{
		USART_USB_write(keys->keys[i]);
		USART_KBD_write(keys->keys[i]);
	}
	for (uint8_t i=0; i < 8; i++)
	{
		USART_USB_write(0x00);
		USART_KBD_write(0x00);
	}
}

bool is_modifier(uint8_t code)
{
	switch(code) {
		case LEFT_CTRL:
		case LEFT_SHIFT:
		case LEFT_ALT:
		case LEFT_GUI:
		case RIGHT_CTRL:
		case RIGHT_SHIFT:
		case RIGHT_ALT:
		case RIGHT_GUI:
			return true;
		default:
			return false;
	}
}

void test_sequence()
{
	HID_Keys_t empty = {.modifier = 0, .keys = {0,0,0,0,0,0}};
	HID_Keys_t ks = {.modifier = LEFT_ALT, .keys = {TAB, 0,0,0,0,0}};
	send_keys(&ks);
	_delay_ms(500);
	send_keys(&empty);
	
}

void init_keyboard_zeros()
{
	HID_Keys_t empty = {.modifier = 0, .keys = {0,0,0,0,0,0}};
	send_keys(&empty);
}

int receive_key_event(Event_t* event)
{
	//char data[10] = "";
	//int idx = 0;
	//while(USART_0_is_rx_ready()) {
		//int ch = USART_0_read();
		//USART_1_write(ch);
		//if (ch == '\n')
			//break;
		//data[idx] = ch;
		//idx++;
	//}
	//printf("%s\n", data);
	uint8_t ch = 0;
	uint8_t packet_len = 0;
	while (USART_KBD_is_rx_ready())
	{
		ch = USART_KBD_read();
		if (ch == '\n')
			return 1;
		// If byte is a digit 0 to 9
		if (packet_len < 2 && (ch >= '0' && ch <= '9')){
			if (packet_len == 0)
				event->key += (ch - '0') * 10;
			else
				event->key += (ch - '0');
			packet_len++;
		}
		else if (packet_len == 2 && ch == ':'){
			packet_len++;
		}
		else if (packet_len == 3 && (ch == PRESSED || ch == RELEASED)) {
			event->event = ch;
		}	
	}
	return 0;
}