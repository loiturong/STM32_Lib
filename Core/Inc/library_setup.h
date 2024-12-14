//
// Created by loitr on 12/14/2024.
//
/*
 * Include declaration for functional setup and built-in function
 * User can activate or deactivate it from setup config. (../Core/Inc/libray_setup_conf.h)
 *
 */

#ifndef LIBRARY_SETUP_H
#define LIBRARY_SETUP_H

/*** GPIO setup function ***/

#ifdef GPIOA_ENABLE
    #include "gpio_a.h"
#endif

#ifdef GPIOB_ENABLE
    #include "gpio_b.h"
#endif


/*** TIMER setup function ***/

#ifdef TIM1_ENABLE
#include "timer_1.h"
#endif

#ifdef TIM2_ENABLE
#include "timer_2.h"
#endif

#ifdef TIM3_ENABLE
#include "timer_1.h"
#endif

#ifdef TIM4_ENABLE
#include "timer_4.h"
#endif

#endif //LIBRARY_SETUP_H
