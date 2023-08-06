#include <avr/io.h>
#include <portpins.h>
#include <util/delay.h>

#include "led_indicator.h"



void blink_led(int times)
{
    for (; times > 0; times--)
    {
        LED_ON;
        _delay_ms(20);
        LED_OFF;
        _delay_ms(20);
    }
    
}