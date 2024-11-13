/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <port.h>

/**
 * \brief Set IS_LEFT output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void IS_LEFT_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTB_set_pin_output_pull_mode(2, output_pull_mode);
}

/**
 * \brief Set IS_LEFT data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void IS_LEFT_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(2, dir);
}

/**
 * \brief Set IS_LEFT input/sense configuration
 *
 * Enable/disable IS_LEFT digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void IS_LEFT_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(2, isc);
}

/**
 * \brief Set IS_LEFT inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on IS_LEFT is inverted
 *                     false = I/O on IS_LEFT is not inverted
 */
static inline void IS_LEFT_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(2, inverted);
}

/**
 * \brief Set IS_LEFT level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void IS_LEFT_set_level(const bool level)
{
	PORTB_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on IS_LEFT
 *
 * Toggle the pin level
 */
static inline void IS_LEFT_toggle_level()
{
	PORTB_toggle_pin_level(2);
}

/**
 * \brief Get level on IS_LEFT
 *
 * Reads the level on a pin
 */
static inline bool IS_LEFT_get_level()
{
	return PORTB_get_pin_level(2);
}

/**
 * \brief Set IS_LEFT interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void IS_LEFT_int_level(const uint8_t level)
{
	PORTB_set_int_level(level);
}

/**
 * \brief Set IS_LEFT interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void IS_LEFT_int0_mask(const uint8_t value)
{
	PORTB_write_int0_mask(value);
}

/**
 * \brief Set IS_LEFT interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void IS_LEFT_int1_mask(const uint8_t value)
{
	PORTB_write_int1_mask(value);
}

/**
 * \brief Set USER_LED output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void USER_LED_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTB_set_pin_output_pull_mode(3, output_pull_mode);
}

/**
 * \brief Set USER_LED data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void USER_LED_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(3, dir);
}

/**
 * \brief Set USER_LED input/sense configuration
 *
 * Enable/disable USER_LED digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void USER_LED_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(3, isc);
}

/**
 * \brief Set USER_LED inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on USER_LED is inverted
 *                     false = I/O on USER_LED is not inverted
 */
static inline void USER_LED_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(3, inverted);
}

/**
 * \brief Set USER_LED level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void USER_LED_set_level(const bool level)
{
	PORTB_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on USER_LED
 *
 * Toggle the pin level
 */
static inline void USER_LED_toggle_level()
{
	PORTB_toggle_pin_level(3);
}

/**
 * \brief Get level on USER_LED
 *
 * Reads the level on a pin
 */
static inline bool USER_LED_get_level()
{
	return PORTB_get_pin_level(3);
}

/**
 * \brief Set USER_LED interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void USER_LED_int_level(const uint8_t level)
{
	PORTB_set_int_level(level);
}

/**
 * \brief Set USER_LED interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void USER_LED_int0_mask(const uint8_t value)
{
	PORTB_write_int0_mask(value);
}

/**
 * \brief Set USER_LED interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void USER_LED_int1_mask(const uint8_t value)
{
	PORTB_write_int1_mask(value);
}

/**
 * \brief Set COL_0 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void COL_0_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set COL_0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void COL_0_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(0, dir);
}

/**
 * \brief Set COL_0 input/sense configuration
 *
 * Enable/disable COL_0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void COL_0_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(0, isc);
}

/**
 * \brief Set COL_0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on COL_0 is inverted
 *                     false = I/O on COL_0 is not inverted
 */
static inline void COL_0_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(0, inverted);
}

/**
 * \brief Set COL_0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void COL_0_set_level(const bool level)
{
	PORTC_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on COL_0
 *
 * Toggle the pin level
 */
static inline void COL_0_toggle_level()
{
	PORTC_toggle_pin_level(0);
}

/**
 * \brief Get level on COL_0
 *
 * Reads the level on a pin
 */
static inline bool COL_0_get_level()
{
	return PORTC_get_pin_level(0);
}

/**
 * \brief Set COL_0 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void COL_0_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set COL_0 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_0_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set COL_0 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_0_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set COL_1 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void COL_1_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set COL_1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void COL_1_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(1, dir);
}

/**
 * \brief Set COL_1 input/sense configuration
 *
 * Enable/disable COL_1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void COL_1_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(1, isc);
}

/**
 * \brief Set COL_1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on COL_1 is inverted
 *                     false = I/O on COL_1 is not inverted
 */
static inline void COL_1_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(1, inverted);
}

/**
 * \brief Set COL_1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void COL_1_set_level(const bool level)
{
	PORTC_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on COL_1
 *
 * Toggle the pin level
 */
static inline void COL_1_toggle_level()
{
	PORTC_toggle_pin_level(1);
}

/**
 * \brief Get level on COL_1
 *
 * Reads the level on a pin
 */
static inline bool COL_1_get_level()
{
	return PORTC_get_pin_level(1);
}

/**
 * \brief Set COL_1 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void COL_1_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set COL_1 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_1_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set COL_1 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_1_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set COL_2 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void COL_2_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(2, output_pull_mode);
}

/**
 * \brief Set COL_2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void COL_2_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(2, dir);
}

/**
 * \brief Set COL_2 input/sense configuration
 *
 * Enable/disable COL_2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void COL_2_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(2, isc);
}

/**
 * \brief Set COL_2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on COL_2 is inverted
 *                     false = I/O on COL_2 is not inverted
 */
static inline void COL_2_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(2, inverted);
}

/**
 * \brief Set COL_2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void COL_2_set_level(const bool level)
{
	PORTC_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on COL_2
 *
 * Toggle the pin level
 */
static inline void COL_2_toggle_level()
{
	PORTC_toggle_pin_level(2);
}

/**
 * \brief Get level on COL_2
 *
 * Reads the level on a pin
 */
static inline bool COL_2_get_level()
{
	return PORTC_get_pin_level(2);
}

/**
 * \brief Set COL_2 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void COL_2_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set COL_2 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_2_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set COL_2 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_2_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set COL_3 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void COL_3_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(3, output_pull_mode);
}

/**
 * \brief Set COL_3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void COL_3_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(3, dir);
}

/**
 * \brief Set COL_3 input/sense configuration
 *
 * Enable/disable COL_3 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void COL_3_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(3, isc);
}

/**
 * \brief Set COL_3 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on COL_3 is inverted
 *                     false = I/O on COL_3 is not inverted
 */
static inline void COL_3_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(3, inverted);
}

/**
 * \brief Set COL_3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void COL_3_set_level(const bool level)
{
	PORTC_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on COL_3
 *
 * Toggle the pin level
 */
static inline void COL_3_toggle_level()
{
	PORTC_toggle_pin_level(3);
}

/**
 * \brief Get level on COL_3
 *
 * Reads the level on a pin
 */
static inline bool COL_3_get_level()
{
	return PORTC_get_pin_level(3);
}

/**
 * \brief Set COL_3 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void COL_3_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set COL_3 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_3_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set COL_3 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_3_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set COL_4 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void COL_4_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(4, output_pull_mode);
}

/**
 * \brief Set COL_4 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void COL_4_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(4, dir);
}

/**
 * \brief Set COL_4 input/sense configuration
 *
 * Enable/disable COL_4 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void COL_4_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(4, isc);
}

/**
 * \brief Set COL_4 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on COL_4 is inverted
 *                     false = I/O on COL_4 is not inverted
 */
static inline void COL_4_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(4, inverted);
}

/**
 * \brief Set COL_4 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void COL_4_set_level(const bool level)
{
	PORTC_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on COL_4
 *
 * Toggle the pin level
 */
static inline void COL_4_toggle_level()
{
	PORTC_toggle_pin_level(4);
}

/**
 * \brief Get level on COL_4
 *
 * Reads the level on a pin
 */
static inline bool COL_4_get_level()
{
	return PORTC_get_pin_level(4);
}

/**
 * \brief Set COL_4 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void COL_4_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set COL_4 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_4_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set COL_4 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_4_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set COL_5 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void COL_5_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(5, output_pull_mode);
}

/**
 * \brief Set COL_5 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void COL_5_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(5, dir);
}

/**
 * \brief Set COL_5 input/sense configuration
 *
 * Enable/disable COL_5 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void COL_5_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(5, isc);
}

/**
 * \brief Set COL_5 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on COL_5 is inverted
 *                     false = I/O on COL_5 is not inverted
 */
static inline void COL_5_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(5, inverted);
}

/**
 * \brief Set COL_5 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void COL_5_set_level(const bool level)
{
	PORTC_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on COL_5
 *
 * Toggle the pin level
 */
static inline void COL_5_toggle_level()
{
	PORTC_toggle_pin_level(5);
}

/**
 * \brief Get level on COL_5
 *
 * Reads the level on a pin
 */
static inline bool COL_5_get_level()
{
	return PORTC_get_pin_level(5);
}

/**
 * \brief Set COL_5 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void COL_5_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set COL_5 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_5_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set COL_5 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_5_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set COL_6 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void COL_6_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(6, output_pull_mode);
}

/**
 * \brief Set COL_6 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void COL_6_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(6, dir);
}

/**
 * \brief Set COL_6 input/sense configuration
 *
 * Enable/disable COL_6 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void COL_6_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(6, isc);
}

/**
 * \brief Set COL_6 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on COL_6 is inverted
 *                     false = I/O on COL_6 is not inverted
 */
static inline void COL_6_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(6, inverted);
}

/**
 * \brief Set COL_6 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void COL_6_set_level(const bool level)
{
	PORTC_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on COL_6
 *
 * Toggle the pin level
 */
static inline void COL_6_toggle_level()
{
	PORTC_toggle_pin_level(6);
}

/**
 * \brief Get level on COL_6
 *
 * Reads the level on a pin
 */
static inline bool COL_6_get_level()
{
	return PORTC_get_pin_level(6);
}

/**
 * \brief Set COL_6 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void COL_6_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set COL_6 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_6_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set COL_6 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void COL_6_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set ROW_0 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void ROW_0_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set ROW_0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ROW_0_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(0, dir);
}

/**
 * \brief Set ROW_0 input/sense configuration
 *
 * Enable/disable ROW_0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void ROW_0_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(0, isc);
}

/**
 * \brief Set ROW_0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ROW_0 is inverted
 *                     false = I/O on ROW_0 is not inverted
 */
static inline void ROW_0_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(0, inverted);
}

/**
 * \brief Set ROW_0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ROW_0_set_level(const bool level)
{
	PORTD_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on ROW_0
 *
 * Toggle the pin level
 */
static inline void ROW_0_toggle_level()
{
	PORTD_toggle_pin_level(0);
}

/**
 * \brief Get level on ROW_0
 *
 * Reads the level on a pin
 */
static inline bool ROW_0_get_level()
{
	return PORTD_get_pin_level(0);
}

/**
 * \brief Set ROW_0 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void ROW_0_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set ROW_0 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROW_0_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set ROW_0 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROW_0_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set ROW_1 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void ROW_1_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set ROW_1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ROW_1_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(1, dir);
}

/**
 * \brief Set ROW_1 input/sense configuration
 *
 * Enable/disable ROW_1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void ROW_1_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(1, isc);
}

/**
 * \brief Set ROW_1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ROW_1 is inverted
 *                     false = I/O on ROW_1 is not inverted
 */
static inline void ROW_1_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(1, inverted);
}

/**
 * \brief Set ROW_1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ROW_1_set_level(const bool level)
{
	PORTD_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on ROW_1
 *
 * Toggle the pin level
 */
static inline void ROW_1_toggle_level()
{
	PORTD_toggle_pin_level(1);
}

/**
 * \brief Get level on ROW_1
 *
 * Reads the level on a pin
 */
static inline bool ROW_1_get_level()
{
	return PORTD_get_pin_level(1);
}

/**
 * \brief Set ROW_1 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void ROW_1_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set ROW_1 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROW_1_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set ROW_1 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROW_1_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set ROW_2 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void ROW_2_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(2, output_pull_mode);
}

/**
 * \brief Set ROW_2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ROW_2_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(2, dir);
}

/**
 * \brief Set ROW_2 input/sense configuration
 *
 * Enable/disable ROW_2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void ROW_2_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(2, isc);
}

/**
 * \brief Set ROW_2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ROW_2 is inverted
 *                     false = I/O on ROW_2 is not inverted
 */
static inline void ROW_2_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(2, inverted);
}

/**
 * \brief Set ROW_2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ROW_2_set_level(const bool level)
{
	PORTD_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on ROW_2
 *
 * Toggle the pin level
 */
static inline void ROW_2_toggle_level()
{
	PORTD_toggle_pin_level(2);
}

/**
 * \brief Get level on ROW_2
 *
 * Reads the level on a pin
 */
static inline bool ROW_2_get_level()
{
	return PORTD_get_pin_level(2);
}

/**
 * \brief Set ROW_2 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void ROW_2_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set ROW_2 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROW_2_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set ROW_2 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROW_2_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set ROW_3 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void ROW_3_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(3, output_pull_mode);
}

/**
 * \brief Set ROW_3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ROW_3_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(3, dir);
}

/**
 * \brief Set ROW_3 input/sense configuration
 *
 * Enable/disable ROW_3 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void ROW_3_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(3, isc);
}

/**
 * \brief Set ROW_3 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ROW_3 is inverted
 *                     false = I/O on ROW_3 is not inverted
 */
static inline void ROW_3_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(3, inverted);
}

/**
 * \brief Set ROW_3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ROW_3_set_level(const bool level)
{
	PORTD_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on ROW_3
 *
 * Toggle the pin level
 */
static inline void ROW_3_toggle_level()
{
	PORTD_toggle_pin_level(3);
}

/**
 * \brief Get level on ROW_3
 *
 * Reads the level on a pin
 */
static inline bool ROW_3_get_level()
{
	return PORTD_get_pin_level(3);
}

/**
 * \brief Set ROW_3 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void ROW_3_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set ROW_3 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROW_3_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set ROW_3 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROW_3_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set ROW_4 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void ROW_4_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(4, output_pull_mode);
}

/**
 * \brief Set ROW_4 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ROW_4_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(4, dir);
}

/**
 * \brief Set ROW_4 input/sense configuration
 *
 * Enable/disable ROW_4 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void ROW_4_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(4, isc);
}

/**
 * \brief Set ROW_4 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ROW_4 is inverted
 *                     false = I/O on ROW_4 is not inverted
 */
static inline void ROW_4_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(4, inverted);
}

/**
 * \brief Set ROW_4 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ROW_4_set_level(const bool level)
{
	PORTD_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on ROW_4
 *
 * Toggle the pin level
 */
static inline void ROW_4_toggle_level()
{
	PORTD_toggle_pin_level(4);
}

/**
 * \brief Get level on ROW_4
 *
 * Reads the level on a pin
 */
static inline bool ROW_4_get_level()
{
	return PORTD_get_pin_level(4);
}

/**
 * \brief Set ROW_4 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void ROW_4_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set ROW_4 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROW_4_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set ROW_4 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROW_4_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set ROW_F output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void ROW_F_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(5, output_pull_mode);
}

/**
 * \brief Set ROW_F data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ROW_F_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(5, dir);
}

/**
 * \brief Set ROW_F input/sense configuration
 *
 * Enable/disable ROW_F digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void ROW_F_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(5, isc);
}

/**
 * \brief Set ROW_F inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ROW_F is inverted
 *                     false = I/O on ROW_F is not inverted
 */
static inline void ROW_F_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(5, inverted);
}

/**
 * \brief Set ROW_F level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ROW_F_set_level(const bool level)
{
	PORTD_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on ROW_F
 *
 * Toggle the pin level
 */
static inline void ROW_F_toggle_level()
{
	PORTD_toggle_pin_level(5);
}

/**
 * \brief Get level on ROW_F
 *
 * Reads the level on a pin
 */
static inline bool ROW_F_get_level()
{
	return PORTD_get_pin_level(5);
}

/**
 * \brief Set ROW_F interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void ROW_F_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set ROW_F interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROW_F_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set ROW_F interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROW_F_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set PD6 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PD6_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(6, output_pull_mode);
}

/**
 * \brief Set PD6 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PD6_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(6, dir);
}

/**
 * \brief Set PD6 input/sense configuration
 *
 * Enable/disable PD6 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PD6_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(6, isc);
}

/**
 * \brief Set PD6 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PD6 is inverted
 *                     false = I/O on PD6 is not inverted
 */
static inline void PD6_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(6, inverted);
}

/**
 * \brief Set PD6 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PD6_set_level(const bool level)
{
	PORTD_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on PD6
 *
 * Toggle the pin level
 */
static inline void PD6_toggle_level()
{
	PORTD_toggle_pin_level(6);
}

/**
 * \brief Get level on PD6
 *
 * Reads the level on a pin
 */
static inline bool PD6_get_level()
{
	return PORTD_get_pin_level(6);
}

/**
 * \brief Set PD6 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PD6_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set PD6 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PD6_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set PD6 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PD6_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set PD7 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PD7_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(7, output_pull_mode);
}

/**
 * \brief Set PD7 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PD7_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(7, dir);
}

/**
 * \brief Set PD7 input/sense configuration
 *
 * Enable/disable PD7 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PD7_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(7, isc);
}

/**
 * \brief Set PD7 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PD7 is inverted
 *                     false = I/O on PD7 is not inverted
 */
static inline void PD7_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(7, inverted);
}

/**
 * \brief Set PD7 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PD7_set_level(const bool level)
{
	PORTD_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on PD7
 *
 * Toggle the pin level
 */
static inline void PD7_toggle_level()
{
	PORTD_toggle_pin_level(7);
}

/**
 * \brief Get level on PD7
 *
 * Reads the level on a pin
 */
static inline bool PD7_get_level()
{
	return PORTD_get_pin_level(7);
}

/**
 * \brief Set PD7 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PD7_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set PD7 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PD7_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set PD7 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PD7_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set PE2 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PE2_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(2, output_pull_mode);
}

/**
 * \brief Set PE2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PE2_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(2, dir);
}

/**
 * \brief Set PE2 input/sense configuration
 *
 * Enable/disable PE2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PE2_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(2, isc);
}

/**
 * \brief Set PE2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PE2 is inverted
 *                     false = I/O on PE2 is not inverted
 */
static inline void PE2_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(2, inverted);
}

/**
 * \brief Set PE2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PE2_set_level(const bool level)
{
	PORTE_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on PE2
 *
 * Toggle the pin level
 */
static inline void PE2_toggle_level()
{
	PORTE_toggle_pin_level(2);
}

/**
 * \brief Get level on PE2
 *
 * Reads the level on a pin
 */
static inline bool PE2_get_level()
{
	return PORTE_get_pin_level(2);
}

/**
 * \brief Set PE2 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PE2_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set PE2 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PE2_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set PE2 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PE2_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

/**
 * \brief Set PE3 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PE3_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(3, output_pull_mode);
}

/**
 * \brief Set PE3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PE3_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(3, dir);
}

/**
 * \brief Set PE3 input/sense configuration
 *
 * Enable/disable PE3 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PE3_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(3, isc);
}

/**
 * \brief Set PE3 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PE3 is inverted
 *                     false = I/O on PE3 is not inverted
 */
static inline void PE3_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(3, inverted);
}

/**
 * \brief Set PE3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PE3_set_level(const bool level)
{
	PORTE_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on PE3
 *
 * Toggle the pin level
 */
static inline void PE3_toggle_level()
{
	PORTE_toggle_pin_level(3);
}

/**
 * \brief Get level on PE3
 *
 * Reads the level on a pin
 */
static inline bool PE3_get_level()
{
	return PORTE_get_pin_level(3);
}

/**
 * \brief Set PE3 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PE3_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set PE3 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PE3_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set PE3 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PE3_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

#endif /* ATMEL_START_PINS_H_INCLUDED */
