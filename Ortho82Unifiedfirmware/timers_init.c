/*******************************************************
Timers/Counters initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator 
Copyright: Neeraj Adsul <neeraj.adsul[at]gmail.com>

Project : Ortho82UnifiedKeyboard
*******************************************************/

// I/O Registers definitions
#include <xmega32a4u.h>

// Disable a Timer/Counter type TC0
void tc0_disable(TC0_t *ptc)
{
// Timer/Counter off
ptc->CTRLA=TC_CLKSEL_OFF_gc;
// Issue a reset command
ptc->CTRLFSET=TC_CMD_RESET_gc;
}

// Disable a Timer/Counter type TC1
void tc1_disable(TC1_t *ptc)
{
// Timer/Counter off
ptc->CTRLA=TC_CLKSEL_OFF_gc;
// Issue a reset command
ptc->CTRLFSET=TC_CMD_RESET_gc;
}

