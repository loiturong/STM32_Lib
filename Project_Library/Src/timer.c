//
// Created by loitr on 12/11/2024.
//

#include "timer.h"
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

        // if (prescaler > 0xFFFF) // Prescaler out of range
        // {
        //     printf("Setup failed. Halting execution...\n");
        //     while(1) {}
        // }
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