/*
 * keymap.h
 *
 * Created: 14/11/2024 18:18:56
 *  Author: neeraj
 */ 


#ifndef KEYMAP_H_
#define KEYMAP_H_

#define nROWS 6
#define nCOLS 7
#define SCAN_DELAY 1 // milliseconds

#define SET_MAX_SIZE 6

typedef struct
{
	int keys[SET_MAX_SIZE];
	int count;
} Keys_t;

void init_set(Keys_t *key_set);
int add_to_set(Keys_t *key_set, char key);
void copy_set(Keys_t* prev_keymap, Keys_t* curr_keymap);
bool is_in_set(Keys_t*, int);
Keys_t* keyboard_scan(Keys_t* keymap);

char* get_key_id(int, int);
uint8_t get_key_code(int key, int is_left);

typedef struct 
{
	uint8_t keys[SET_MAX_SIZE];		
	uint8_t modifier;
} HID_Keys_t;

//void send_keys(HID_Keys_t *);

#endif /* KEYMAP_H_ */