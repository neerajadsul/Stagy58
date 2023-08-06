/**
 * Ortho82 Keyboard Firmware Main File
 * Author: Neeraj Adsul 
 * Email: neeraj[at]125systems[dot]com
 * Copyright 2023 Neeraj Adsul
*/

#include <avr/io.h>

#include "system_clock.h"
#include "ports.h"
#include "usart.h"
#include "usb.h"

main()
{
    system_clock_init();
    ports_init();
    usart_init();
    usb_init();
    while (1)
    {
        /* code */
    }
    
}

