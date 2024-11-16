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

#define SET_MAX_SIZE 5

typedef struct
{
	int buffer[SET_MAX_SIZE];
	int count;
} Set_t;

void init_set(Set_t *key_set);
int add_to_set(Set_t *key_set, char key);
void copy_set(Set_t* prev_keymap, Set_t* curr_keymap);
bool is_in_set(Set_t*, int);
Set_t* keyboard_scan(Set_t* keymap);

char* get_key_id(int);

#endif /* KEYMAP_H_ */