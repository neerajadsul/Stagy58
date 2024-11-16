#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>

#include "keymap.h"
#include "version.h"

#define PRESSED		'P'
#define RELEASED	'R'

typedef struct {
	int key;
	int event;	
} Event_t;

void send_key_event(int key, int event);
int receive_key_event(Event_t* event);

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
				send_key_event(key, PRESSED);
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
				printf("%d: %c\n", key_event.key, key_event.event);
			}
		}
		
	}
}


void send_key_event(int key, int event)
{
	USART_0_write('0' + (int)key/10);
	USART_0_write('0' + key%10);
	USART_0_write(':');
	USART_0_write(event);
	USART_0_write('\n');
}


int receive_key_event(Event_t* event)
{
	char data[10]; 
	if (!USART_0_is_rx_ready())
	{
		return 0;
	}
	
	int idx = 0;
	while(1) {
		int ch = USART_0_read();
		if (ch == '\n')
			break;
		data[idx] = ch;
		idx++;
	}
	printf("%s\n", data);
	return 0;
	//int data = 0;
	//int packet_len = 0;
	//do 
	//{
		//data = USART_0_read();
		//// If byte is a digit 0 to 9
		//if (packet_len < 2 && (data >= '0' && data <= '9')){
			//if (packet_len == 0)
				//event->key += (data - '0') * 10;
			//else
				//event->key += (data - '0');
			//packet_len++;
		//}
		//else if (packet_len == 2 && data == ':'){
			//packet_len++;
		//}
		//else if (packet_len == 3 && (data == PRESSED || data == RELEASED)) {
			//event->event = data;
		//}
		//
	//} while (data != '\n');
	//return 1;
}