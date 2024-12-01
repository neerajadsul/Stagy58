/*******************************************************
Timers/Counters initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator
© Copyright 1998-2019 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : SplitKeyboardPS2
*******************************************************/

#ifndef _TIMERS_INIT_INCLUDED_
#define _TIMERS_INIT_INCLUDED_

// Disable a Timer/Counter type TC0
void tc0_disable(TC0_t *ptc);
// Disable a Timer/Counter type TC1
void tc1_disable(TC1_t *ptc);
// Timer/Counter TCD0 initialization
void tcd0_init(void);

#endif
