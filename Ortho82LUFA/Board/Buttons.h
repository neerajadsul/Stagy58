// #ifndef __BUTTONS_H__
// #define __BUTTONS_H__


#define ROW_MASK    0x3F
#define BUTTONS_ESCAPE  0x01
#define BUTTONS_E       0xEF


static inline void Buttons_Init(void)
{
    PORTC.DIR = 0xFF;
    PORTC.OUTSET |= 0xEF;
    PORTD.DIRSET |= 0x3F;
}
static inline void Buttons_Disable(void)
{
    PORTC.OUTCLR &= 0x80;
}
static inline uint_reg_t Buttons_GetStatus(void)
{
    return PORTD.IN & ROW_MASK;
}
// void Buttons_Init(void);
// void Buttons_Disable(void);
// uint_reg_t Buttons_GetStatus(void);

// #endif