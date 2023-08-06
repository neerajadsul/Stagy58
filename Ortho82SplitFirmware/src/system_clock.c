#include <xmega.h>
#include <stddef.h>
#include <interrupt.h>
#include <avr/io.h>>

#include "system_clock.h"


void system_clock_init()
{
    // Global interrupt disable
    cli();
    // 32MHz internal oscillator
    CLK_CTRL = OSC_RC32MCREF0_bm;
    // Prescaler: A Divide by 2, B Divide by 2, C divide by 2
    CLK_PSCTRL = CLK_PSADIV2_bm | CLK_PSBCDIV_gm;
}