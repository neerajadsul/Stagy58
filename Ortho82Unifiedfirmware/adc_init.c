/*******************************************************
ADC initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator
© Copyright 1998-2019 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : SplitKeyboardPS2
*******************************************************/

// I/O Registers definitions
#include <xmega32a4u.h>

// Delay functions
#include <delay.h>

// ADC initialization functions
#include "adc_init.h"

// ADCA initialization
void adca_init(void)
{
// ADCA is disabled
ADCA.CTRLA=0;
}

