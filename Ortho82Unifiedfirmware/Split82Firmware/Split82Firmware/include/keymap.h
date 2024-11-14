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


#define SET_MAX_SIZE 5

typedef struct
{
	int buffer[SET_MAX_SIZE];
	int count;
} Set_t;

void init_set(Set_t *key_set);
int add_to_set(Set_t *key_set, char key);

Set_t* keyboard_scan(Set_t*);

char* get_key_id(int);

#endif /* KEYMAP_H_ */