/*******************************************************
Analog Comparator(s) initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator
© Copyright 1998-2019 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : SplitKeyboardPS2
*******************************************************/

// I/O Registers definitions
#include <xmega32a4u.h>

// Analog Comparator(s) for PORTA initialization
void aca_init(void)
{
// Window Mode is disabled
ACA.WINCTRL=(0<<AC_WEN_bp);
// AC0 and AC1 Constant Current Sources are disabled
ACA.CURRCTRL=(0<<AC_CURREN_bp) | (0<<AC_AC1CURR_bp) | (0<<AC_AC0CURR_bp);
// AC0 is disabled
ACA.AC0CTRL=(0<<AC_ENABLE_bp);
// AC1 is disabled
ACA.AC1CTRL=(0<<AC_ENABLE_bp);
// AC0 Output on PORTA: No
// AC1 Output on PORTA: No
ACA.CTRLA=(0<<AC_AC1OUT_bp) | (0<<AC_AC0OUT_bp);
}

