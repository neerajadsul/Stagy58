/*******************************************************
System clock initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator
© Copyright 1998-2019 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : SplitKeyboardPS2
*******************************************************/

// I/O Registers definitions
#include <xmega32a4u.h>

// Standard definitions
#include <stddef.h>

// System Clocks initialization
void system_clocks_init(void)
{
unsigned char n,s;

// Optimize for speed
#pragma optsize- 
// Save interrupts enabled/disabled state
s=SREG;
// Disable interrupts
#asm("cli")

// Internal 32 kHz RC oscillator initialization
// Enable the internal 32 kHz RC oscillator
OSC.CTRL|=OSC_RC32KEN_bm;
// Wait for the internal 32 kHz RC oscillator to stabilize
while ((OSC.STATUS & OSC_RC32KRDY_bm)==0);

// Internal 32 MHz RC oscillator initialization
// Internal 32 MHz RC osc. calibration reference clock source: Internal 32kHz RC oscillator

// Oscillator calibration not enabled yet
DFLLRC32M.CTRL=0<<DFLL_ENABLE_bp;

// Enable the internal 32 MHz RC oscillator
OSC.CTRL|=OSC_RC32MEN_bm;
// Wait for the internal 32 MHz RC oscillator to stabilize
while ((OSC.STATUS & OSC_RC32MRDY_bm)==0);

// Use the Internal 32kHz RC oscillator as DFLL clock reference
OSC.DFLLCTRL=(OSC.DFLLCTRL & (~OSC_RC32MCREF_gm)) | OSC_RC32MCREF_RC32K_gc;

// Enable the auto-calibration of the internal 32 MHz RC oscillator
DFLLRC32M.CTRL=1<<DFLL_ENABLE_bp;

// System Clock prescaler A division factor: 2
// System Clock prescalers B & C division factors: B:1, C:1
// ClkPer4: 16000.000 kHz
// ClkPer2: 16000.000 kHz
// ClkPer:  16000.000 kHz
// ClkCPU:  16000.000 kHz
n=(CLK.PSCTRL & (~(CLK_PSADIV_gm | CLK_PSBCDIV1_bm | CLK_PSBCDIV0_bm))) |
	CLK_PSADIV_2_gc | CLK_PSBCDIV_1_1_gc;
CCP=CCP_IOREG_gc;
CLK.PSCTRL=n;

// Select the system clock source: 32 MHz Internal RC Osc.
n=(CLK.CTRL & (~CLK_SCLKSEL_gm)) | CLK_SCLKSEL_RC32M_gc;
CCP=CCP_IOREG_gc;
CLK.CTRL=n;

// PLL initialization
// Ensure that the PLL is disabled before configuring it
OSC.CTRL&= ~OSC_PLLEN_bm;
// PLL clock source: 32 MHz RC Oscillator/4
// PLL multiplication factor: 6
// PLL output/2: Off
// PLL frequency: 48 MHz
// Set the PLL clock source and multiplication factor
n=OSC_PLLSRC_RC32M_gc | (0<<OSC_PLLDIV_bp) | (6<<OSC_PLLFAC_gp);
// Enable the PLL
CCP=CCP_IOREG_gc;
OSC.PLLCTRL=n;
OSC.CTRL|=OSC_PLLEN_bm;

// Wait for the PLL to stabilize
while ((OSC.STATUS & OSC_PLLRDY_bm)==0);

// Disable the unused oscillators: 2 MHz, external clock/crystal oscillator
OSC.CTRL&= ~(OSC_RC2MEN_bm | OSC_XOSCEN_bm);

// ClkPer output disabled
PORTCFG.CLKEVOUT&= ~(PORTCFG_CLKOUTSEL_gm | PORTCFG_CLKOUT_gm);
// Restore interrupts enabled/disabled state
SREG=s;
// Restore optimization for size if needed
#pragma optsize_default
}

