/*******************************************************
ADC initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator 
Copyright: Neeraj Adsul <neeraj.adsul[at]gmail.com>

Project : Ortho82UnifiedKeyboard
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

