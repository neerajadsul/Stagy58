/**
 * Ortho82 Keyboard Firmware Main File
 * Author: Neeraj Adsul 
 * Email: neeraj[at]125systems[dot]com
 * Copyright 2023 Neeraj Adsul
*/



#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

// #define _ALTERNATE_PUTCHAR_
// #define _ALTERNATE_GETCHAR_

#include "system_clock.h"
#include "ports.h"
#include "usart.h"
#include "usb.h"
#include "led_indicator.h"

main()
{
    system_clock_init();
    ports_init();
    usart_init();
    usb_init();
    while (1)
    {
        LED_ON;
        _delay_ms(25);
        LED_OFF;
        _delay_ms(12);
        sendchar('M');
        _delay_ms(13);
    }
    
}

