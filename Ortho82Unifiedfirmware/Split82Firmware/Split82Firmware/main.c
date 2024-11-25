#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>

#include "keymap.h"
#include "keycodes.h"
#include "version.h"

#define PRESSED		'P'
#define RELEASED	'R'

typedef struct {
	int key;
	int event;	
} Event_t;

void send_key_event(int key, int event);
int receive_key_event(Event_t* event);
void send_alt_tab(void);

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
	static Event_t key_event;
	int is_left_half = IS_LEFT_get_level() ? 0 : 1;
	printf("Is Left Half %d", is_left_half);
	//while(USART_0_is_rx_ready()) USART_0_read();
	while (1) {
		init_set(&curr_keymap);
		keyboard_scan(&curr_keymap);
		for (int i=0; i < curr_keymap.count; i++)
		{	
			// Currently pressed keys
			int key = curr_keymap.keys[i];
			if (!is_in_set(&prev_keymap, key))
			{
				printf("%c 1 %s\n", is_left_half ? 'L':'R', get_key_id(key, is_left_half));
				//send_alt_tab();
				USER_LED_toggle_level();
				send_key_event(key, PRESSED);
			}			
		}
		for (int i=0; i<prev_keymap.count ; i++)
		{
			// Released keys as they were previously pressed but not anymore
			int key = prev_keymap.keys[i];
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


void send_key_event(int key, int event)
{
	USART_KBD_write('0' + (int)key/10);
	USART_KBD_write('0' + key%10);
	USART_KBD_write(':');
	USART_KBD_write(event);
	USART_KBD_write('\n');
}

void send_alt_tab()
{
	uint8_t keys[8] = {LEFT_ALT, 0x00, TAB, 0x00, 0x00, 0x00, 0x00, 0x00};
	for (int i=0; i < 8; i++)
	{
		USART_USB_write(keys[i]);
		_delay_us(10);
	}
	for (int i=0; i < 8; i++)
	{
		USART_USB_write(0x00);
		_delay_us(10);
	}
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
	int ch = 0;
	int packet_len = 0;
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