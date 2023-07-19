/*******************************************************
SPI initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator
Copyright: Neeraj Adsul <neeraj.adsul[at]gmail.com>

Project : Ortho82UnifiedKeyboard
*******************************************************/

// I/O Registers definitions
#include <xmega32a4u.h>

// SPIC initialization
void spic_init(void)
{
// SPIC is disabled
SPIC.CTRL=0;

// SPIC interrupt: Disabled
SPIC.INTCTRL=SPI_INTLVL_OFF_gc;

// Note: The MOSI (PORTC, Pin 5), SCK (PORTC, Pin 7) and /SS (PORTC, Pin 4)
// signals are configured as outputs in the ports_init function.
}

// SPID initialization
void spid_init(void)
{
// SPID is disabled
SPID.CTRL=0;

// SPID interrupt: Disabled
SPID.INTCTRL=SPI_INTLVL_OFF_gc;

// Note: The MOSI (PORTD, Pin 5), SCK (PORTD, Pin 7) and /SS (PORTD, Pin 4)
// signals are configured as outputs in the ports_init function.
}

