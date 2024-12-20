//
// Created by loitr on 12/13/2024.
//

#include "stm32f1xx.h"
#include "timer.h"
#include "timer_2.h"
#include "gpio_a.h"

#include <stdlib.h>

void TIM2_Internal_Setup(int period_ms)
{
    // Enable Clock for Timer
    RCC->APB1ENR |= TIM2_APB1ENR_ENABLE;
    // Set Prescaler and Auto-Reload for timer
    int* temp_ = find_timer_configuration(period_ms, HSI_VALUE);
    TIM2->ARR = temp_[0];
    TIM2->PSC = temp_[1];
    free(temp_); // free memory
    TIM2->CR1 |= CR_COUNT_ENR;
}

void TIM2_External_Setup(int period_ms)
{
    // Enable Clock for Timer
    RCC->APB1ENR |= TIM2_APB1ENR_ENABLE;
    // enable slave mode External clock mode
    TIM2->SMCR &= ~(SMS_RESET);
    TIM2->SMCR |= SMS_EXT_CLOCK;
    // Set trigger source
    TIM2->SMCR &= ~(TS_RESET);
    TIM2->SMCR |= TS_EXTER_TRIG;

    // Set Prescaler and Auto-Reload for timer
    int* temp_ = find_timer_configuration(period_ms, HSE_VALUE);
    TIM2->ARR = temp_[0];
    TIM2->PSC = temp_[1];
    free(temp_); // free memory
    TIM2->CR1 |= CR_COUNT_ENR;
}

void TIM2_Activate(void)
{
    // Enable Update Interrupt
    TIM2->DIER |= DIER_UP_ENR;
    // Enable Interrupt setup enable register in NVIC module
    NVIC->ISER[0] |= ISER_TIM2_GLOBAL_ENR;
}

void TIM2_PWM_Channel1_Setup(int period_ms, float duty_cycle)
{
    // Enable Clock for pinout
    GPIOA_Setup(0, MODE_Output_10MHz, CNF_AF_PUSH_PULL);

    // Setup timer 2
    TIM2_Internal_Setup(period_ms);

    // Setup Pulse width for channel 1
    TIM2->CCR1 = (int)(TIM2->ARR * duty_cycle);
    TIM2->CCMR1 |= (CCMR_OCM_MODE_2 << 4); // mode (....|'''')

    // Enable output compare for Channel 1
    TIM2->CCER |= CCER_CH1_ENR;
}
