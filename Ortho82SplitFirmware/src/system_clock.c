// #include <xmega.h>
// #include <stddef.h>
// #include <interrupt.h>
// #include <avr/io.h>>

// #include "system_clock.h"


// void system_clock_init()
// {
//     // Global interrupt disable
//     cli();

//     // Oscillator Calibration not enabled yet
//     DFLLRC32M.CTRL = 0 << DFLL_ENABLE_bp;

//     // 32MHz internal oscillator
//     OSC_CTRL |= OSC_RC32MEN_bm;
//     // CLK_CTRL = CLK_SCLKSEL_RC32M_gc;

//     while (OSC_STATUS & OSC_RC32MRDY_bm)
//     {
//         // wait until 32MHz internal oscillator is ready.
//     }
    
//     // Prescaler: A Divide by 2, B Divide by 2, C divide by 2
//     CLK_PSCTRL = CLK_PSADIV_2_gc | CLK_PSBCDIV_1_2_gc;

//     // Enable global interrupts
//     sei();
// }