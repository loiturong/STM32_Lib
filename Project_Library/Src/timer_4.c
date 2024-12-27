//
// Created by loitr on 12/13/2024.
//
#include "stm32f1xx.h"
#include "timer.h"
#include "timer_4.h"
#include "gpio_b.h"

#include <stdlib.h>


void TIM4_Setup(int period_ms)
{
    // Enable Clock for Timer
    RCC->APB1ENR |= TIM4_APB1ENR_ENABLE;
    // Set Prescaler and Auto-Reload for timer
    int* temp_ = find_timer_configuration(period_ms, HSI_VALUE);
    TIM4->ARR = temp_[0];
    TIM4->PSC = temp_[1];
    free(temp_); // free memory
    TIM4->CR1 |= CR_COUNT_ENR;
}

void TIM4_Activate(void)
{
    // Enable Update Interrupt
    TIM4->DIER |= DIER_UP_ENR;
    // Enable Interrupt setup enable register in NVIC module
    NVIC->ISER[0] |= ISER_TIM4_GLOBAL_ENR;
}

void TIM4_Deactivate(void)
{
    // Enable Update Interrupt
    TIM4->DIER &= ~(DIER_UP_ENR);
    // Enable Interrupt setup enable register in NVIC module
    NVIC->ISER[0] &= ~(ISER_TIM4_GLOBAL_ENR);
}

void TIM4_PWM_Channel1_Setup(int period_ms, float duty_cycle)
{
    // Enable Clock for PB6 pin
    GPIOB_Setup(6, MODE_Output_10MHz, CNF_AF_PUSH_PULL);

    // Setup timer 4
    TIM4_Setup(period_ms);

    // Setup Pulse width for channel 1
    TIM4->CCR1 = (int)(TIM4->ARR * duty_cycle);
    TIM4->CCMR1 |= (CCMR_OCM_MODE_2 << 4); // mode (....|'''')

    // Enable output compare for Channel 1
    TIM4->CCER |= CCER_CH1_ENR;
}

void TIM4_PWM_Channel2_Setup(int period_ms, float duty_cycle)
{
    // Enable Clock for PB7 pin
    GPIOB_Setup(7, MODE_Output_10MHz, CNF_AF_PUSH_PULL);

    // Setup timer 4
    TIM4_Setup(period_ms);

    // Setup Pulse width for channel 1
    TIM4->CCR2 = (int)(TIM4->ARR * duty_cycle);
    TIM4->CCMR1 |= (CCMR_OCM_MODE_2 << 12); // mode (....|'''')

    // Enable output compare for Channel 1
    TIM4->CCER |= CCER_CH2_ENR;
}

void TIM4_PWM_Channel3_Setup(int period_ms, float duty_cycle)
{
    // Enable Clock for PB8 pin
    GPIOB_Setup(8, MODE_Output_10MHz, CNF_AF_PUSH_PULL);

    // Setup timer 4
    TIM4_Setup(period_ms);

    // Setup Pulse width for channel 1
    TIM4->CCR3 = (int)(TIM4->ARR * duty_cycle);
    TIM4->CCMR2 |= (CCMR_OCM_MODE_2 << 4); // mode (....|'''')

    // Enable output compare for Channel 1
    TIM4->CCER |= CCER_CH3_ENR;
}

void TIM4_PWM_Channel4_Setup(int period_ms, float duty_cycle)
{
    // Enable Clock for PB9 pin
    GPIOB_Setup(9, MODE_Output_10MHz, CNF_AF_PUSH_PULL);

    // Setup timer 4
    TIM4_Setup(period_ms);

    // Setup Pulse width for channel 4
    TIM4->CCR4 = (int)(TIM4->ARR * duty_cycle);
    TIM4->CCMR2 |= (CCMR_OCM_MODE_2 << 12); // mode (....|'''')

    // Enable output compare for Channel 1
    TIM4->CCER |= CCER_CH4_ENR;
}

void TIM4_Counter_Setup(int counts)
{
    // Enable Clock for Timer
    RCC->APB1ENR |= TIM4_APB1ENR_ENABLE;
    /*** first approach ***/
    // // enable slave mode External clock mode
    // TIM4->SMCR &= ~(SMS_RESET);
    // TIM4->SMCR |= SMS_EXT_CLOCK;
    // // Set trigger source
    // TIM4->SMCR &= ~(TS_RESET);
    // TIM4->SMCR |= TS_EXTER_TRIG;
    /*** first approach ***/
    TIM4->PSC = 0;
    TIM4->ARR = counts;
    TIM4->SMCR |= 1<<14;

    TIM4->CR1 |= CR_COUNT_ENR;
}