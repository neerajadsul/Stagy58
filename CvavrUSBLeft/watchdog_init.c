/*******************************************************
Watchdog Timer initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator
© Copyright 1998-2019 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : SplitKeyboardPS2
*******************************************************/

// I/O Registers definitions
#include <xmega32a4u.h>

// Watchdog Timer initialization
void watchdog_init(void)
{
unsigned char s,n;

// Optimize for speed
#pragma optsize- 
// Save interrupts enabled/disabled state
s=SREG;
// Disable interrupts
#asm("cli")

// Watchdog Timer: Off
n=(WDT.CTRL & (~WDT_ENABLE_bm)) | WDT_CEN_bm;
CCP=CCP_IOREG_gc;
WDT.CTRL=n;
// Watchdog window mode: Off
n=(WDT.WINCTRL & (~WDT_WEN_bm)) | WDT_WCEN_bm;
CCP=CCP_IOREG_gc;
WDT.WINCTRL=n;

// Restore interrupts enabled/disabled state
SREG=s;
// Restore optimization for size if needed
#pragma optsize_default
}

