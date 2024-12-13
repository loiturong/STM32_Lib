//
// Created by loitr on 12/13/2024.
//

/**
 * Configures Timer 1 (TIM1) for a specified time period and frequency.
 *
 * This function enables the clock for Timer 1, calculates the appropriate
 * prescaler (PSC) and auto-reload register (ARR) values using the compute_value
 * function, and sets these values for Timer 1. After setting up, the allocated
 * memory for the computed values is freed.
 *
 * @param period_ms The desired time period in milliseconds.
 * @param frequency The frequency in Hertz at which Timer 1 should operate.
 */
// void TIM1_Setup(int period_ms, int frequency)
// {
//     // Enable Clock for Timer
//     RCC->APB2ENR |= TIM1_ENABLE;
//     // Set Prescaler and Auto-Reload for timer
//     int* temp_ = compute_value(period_ms, frequency);
//     TIM1->ARR = temp_[0];
//     TIM1->PSC = temp_[1];
//     free(temp_); // free memory
//     TIM1->CR1 |= (1 << 0);
// }

/**
 * Enables the TIM1 update interrupt and sets up the corresponding interrupt in the NVIC module.
 *
 * This function activates the update interrupt for TIM1 by setting the appropriate bit
 * in the TIM1 DMA/Interrupt Enable Register (DIER). It also enables the interrupt for
 * TIM1 in the Nested Vectored Interrupt Controller (NVIC) by setting the corresponding
 * bit in the NVIC Interrupt Set Enable Register (ISER).
 */
// void TIM1_Activate(void)
// {
//     // Enable Update Interrupt
//     TIM1->DIER |= (1 << 0);
//     // Enable Interrupt setup enable register in NVIC module
//     NVIC->ISER[0] |= (1 << 25);
// }