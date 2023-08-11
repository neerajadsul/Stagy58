#ifndef __LEDS_H__
#define __LEDS_H__
            
#include <avr/io.h>

static inline void       LEDs_Init(void) {
    PORTB.DIR = 0x08;
}
static inline void       LEDs_Disable(void) {
}
static inline void       LEDs_TurnOnLEDs(const uint_reg_t LEDMask) {
    PORTB.OUTCLR = 1 << 3;
}
static inline void       LEDs_TurnOffLEDs(const uint_reg_t LEDMask) {
    PORTB.OUTSET = 1 << 3;
}
static inline void       LEDs_SetAllLEDs(const uint_reg_t LEDMask) {

}
static inline void       LEDs_ChangeLEDs(const uint_reg_t LEDMask, const uint_reg_t ActiveMask) {}
static inline void       LEDs_ToggleLEDs(const uint_reg_t LEDMask) {
    PORTB.OUTTGL = 1 << 3;
}
static inline uint_reg_t LEDs_GetLEDs(void) { return 0; }

#endif