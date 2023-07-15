/*******************************************************
RTC initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator 
Copyright: Neeraj Adsul <neeraj.adsul[at]gmail.com>

Project : Ortho82UnifiedKeyboard
*******************************************************/

// I/O Registers definitions
#include <xmega32a4u.h>

// RTC initialization
void rtcxm_init(void)
{
// No clock source for the RTC
CLK.RTCCTRL&= ~CLK_RTCEN_bm;
// RTC stopped
RTC.CTRL=RTC_PRESCALER_OFF_gc;
// RTC overflow interrupt: Off
// RTC compare interrupt: Off
RTC.INTCTRL=RTC_OVFINTLVL_OFF_gc | RTC_COMPINTLVL_OFF_gc;
// RTC Clock output disabled
PORTCFG.CLKEVOUT&= ~PORTCFG_RTCOUT_bm;
}

