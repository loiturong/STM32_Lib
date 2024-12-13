//
// Created by loitr on 12/11/2024.
//
#include "stm32f1xx.h"
#include "address.h"

#include "gpio.h"


/**
 * @brief Configures a specific GPIO pin on GPIOA.
 *
 * This function sets up a GPIO pin on port GPIOA with the specified configuration
 * and mode by enabling the GPIOA clock and updating the configuration register.
 *
 * @param pin The pin number to configure (0-7). Each pin represents a 4-bit field
 *            in the configuration register.
 * @param cnf The configuration setting for the GPIO pin. It is a 2-bit value
 *            determining the pin's functional configuration (e.g., input/output type).
 * @param mode The mode setting for the GPIO pin. It is a 2-bit value determining
 *             the pin I/O mode (e.g., input, output at specific speed).
 */
void GPIOA_Setup(int pin, int mode, int cnf)
{
    RCC->APB2ENR |= GPIOA_ENABLE;
    if (pin < 8)
        GPIOA->CRL |= (((cnf << 2) | mode) << pin * 4);
    else
        GPIOA->CRH |= (((cnf << 2) | mode) << (pin - 8) * 4);
}

/**
 * @brief Configures the pull-up or pull-down resistor for a specific GPIO pin on GPIOA.
 *
 * This function enables the GPIOA peripheral, configures the specified GPIO pin
 * as an input with a pull-up or pull-down resistor, and sets the desired pull state.
 *
 * @param pin The GPIO pin number to configure (0-15).
 * @param pull_up Specifies the pull state:
 *                0 for pull-down,
 *                1 for pull-up.
 */
void GPIOA_Pull_Setup(int pin, int pull_up)
{
    GPIOA_Setup(pin, MODE_Input, CNF_Input_Pull);
    if (pull_up)
        GPIOA->ODR |= (pull_up << pin);
    else
        GPIOA->ODR &= ~(pull_up << pin);
}

/**
 * @brief Configures a specific GPIO pin on GPIOB.
 *
 * This function sets up a GPIO pin on port GPIOB with the given configuration
 * and mode. It first enables the GPIOB clock, and then updates the appropriate
 * configuration register (CRL or CRH) based on the pin number.
 *
 * @param pin The pin number to configure (0-15). Pins 0-7 are configured via the CRL register,
 *            and pins 8-15 are configured via the CRH register.
 * @param mode The mode setting for the GPIO pin. It is a 2-bit value that determines
 *             the pin's input/output mode (e.g., input, output at specific speed).
 * @param cnf The configuration setting for the GPIO pin. It is a 2-bit value that
 *            determines the pin's functional configuration (e.g., input/output type).
 */
void GPIOB_Setup(int pin, int mode, int cnf)
{
    RCC->APB2ENR |= GPIOB_ENABLE;
    if (pin < 8)
        GPIOB->CRL |= (((cnf << 2) | mode) << pin * 4);
    else
        GPIOB->CRH |= (((cnf << 2) | mode) << (pin - 8) * 4);
}

/**
 * @brief Configures a GPIO pin on GPIOB with pull-up or pull-down resistor.
 *
 * This function sets a GPIO pin on port GPIOB as an input with pull-up or
 * pull-down resistor configuration by modifying the corresponding registers.
 *
 * @param pin The pin number to configure (0-15). Each pin represents a 4-bit field
 *            in the configuration register.
 * @param pull_up Determines whether a pull-up or pull-down resistor is applied.
 *                Use a non-zero value for a pull-up resistor, or zero for a pull-down resistor.
 */
void GPIOB_Pull_Setup(int pin, int pull_up)
{
    GPIOB_Setup(pin, MODE_Input, CNF_Input_Pull);
    if (pull_up)
        GPIOB->ODR |= (1 << pin);
    else
        GPIOB->ODR &= ~(1 << pin);
}