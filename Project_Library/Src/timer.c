//
// Created by loitr on 12/11/2024.
//
#include "stm32f1xx.h"
#include "address.h"

#include "timer.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Computes the auto-reload register (ARR) and prescaler (PSC) values
 * for a timer based on the given period and frequency.
 *
 * The function calculates the ARR and PSC such that the product of the period
 * and frequency fits within the maximum timer value. It returns a dynamically
 * allocated array containing the computed ARR and PSC values, choosing the
 * maximum ARR value for potential later use in PWM mode.
 *
 * @param period_ms The desired period in milliseconds.
 * @param frequency The frequency in Hertz at which the timer should operate.
 * @return A pointer to an integer array of size 2 where:
 *         - The first element is the computed ARR value.
 *         - The second element is the computed PSC value.
 *         If memory allocation fails, the function returns NULL.
 */
#define MAX_TIMER_VALUE 65536

int *compute_value(int period_ms, int frequency)
{
    // Avoid floating-point operations
    long long int time_frequency = (long long int)period_ms * frequency / 1000;
    int prescaler = 1;

    // Ensure prescaler divides correctly
    while (time_frequency > MAX_TIMER_VALUE)
    {
        prescaler += 1;

        // Adjust time frequency with the updated prescaler
        time_frequency = (long long int)period_ms * frequency / (1000 * prescaler);

        if (prescaler > 0xFFFF) // Prescaler out of range
        {
            printf("Setup failed. Halting execution...\n");
            while(1) {}
        }
    }

    // Allocate memory for the result
    int *result = malloc(2 * sizeof(int));
    if (result == NULL)
    {
        return NULL; // Handle allocation failure
    }

    result[0] = (int)time_frequency - 1; // ARR
    result[1] = prescaler - 1;          // PSC

    return result;
}

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
void TIM1_Setup(int period_ms, int frequency)
{
    // Enable Clock for Timer
    RCC->APB2ENR |= TIM1_ENABLE;
    // Set Prescaler and Auto-Reload for timer
    int* temp_ = compute_value(period_ms, frequency);
    TIM1->ARR = temp_[0];
    TIM1->PSC = temp_[1];
    free(temp_); // free memory
    TIM1->CR1 |= (1 << 0);
}

/**
 * Enables the TIM1 update interrupt and sets up the corresponding interrupt in the NVIC module.
 *
 * This function activates the update interrupt for TIM1 by setting the appropriate bit
 * in the TIM1 DMA/Interrupt Enable Register (DIER). It also enables the interrupt for
 * TIM1 in the Nested Vectored Interrupt Controller (NVIC) by setting the corresponding
 * bit in the NVIC Interrupt Set Enable Register (ISER).
 */
void TIM1_Activate(void)
{
    // Enable Update Interrupt
    TIM1->DIER |= (1 << 0);
    // Enable Interrupt setup enable register in NVIC module
    NVIC->ISER[0] |= (1 << 25);
}

void TIM2_Setup(int period_ms, int frequency)
{
    // Enable Clock for Timer
    RCC->APB1ENR |= TIM2_ENABLE;
    // Set Prescaler and Auto-Reload for timer
    int* temp_ = compute_value(period_ms, frequency);
    TIM2->ARR = temp_[0];
    TIM2->PSC = temp_[1];
    free(temp_); // free memory
    TIM2->CR1 |= (1 << 0);
}

void TIM2_Activate(void)
{
    // Enable Update Interrupt
    TIM2->DIER |= (1 << 0);
    // Enable Interrupt setup enable register in NVIC module
    NVIC->ISER[0] |= (1 << 28);
}