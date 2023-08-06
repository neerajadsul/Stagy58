#ifndef LED_INDICATOR_H
#define LED_INDICATOR_H


// LED connection is active low
#define LED_PORT PORTB
#define LED_PIN PIN3_bm
#define LED_ON (PORTB_OUTCLR |= 0x08)
#define LED_OFF (PORTB_OUTSET |= 0x08)

void blink_led(int times); 

#endif