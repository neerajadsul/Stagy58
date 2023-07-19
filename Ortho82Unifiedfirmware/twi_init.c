/*******************************************************
TWI initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator 
Copyright: Neeraj Adsul <neeraj.adsul[at]gmail.com>

Project : Ortho82UnifiedKeyboard
*******************************************************/

// I/O Registers definitions
#include <xmega32a4u.h>

// TWI initialization functions
#include "twi_init.h"

// TWIC initialization
void twic_init(void)
{
// General TWIC initialization
// External Driver Interface: Off
// SDA Hold: Off
TWIC.CTRL&= ~(TWI_SDAHOLD_gm | TWI_EDIEN_bm);

// TWIC Master is disabled
TWIC.MASTER.CTRLA=0;

// TWIC Slave is disabled
TWIC.SLAVE.CTRLA=0;
}

// TWIE initialization
void twie_init(void)
{
// General TWIE initialization
// External Driver Interface: Off
// SDA Hold: Off
TWIE.CTRL&= ~(TWI_SDAHOLD_gm | TWI_EDIEN_bm);

// TWIE Master is disabled
TWIE.MASTER.CTRLA=0;

// TWIE Slave is disabled
TWIE.SLAVE.CTRLA=0;
}

