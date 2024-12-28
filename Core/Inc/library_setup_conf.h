//
// Created by loitr on 12/13/2024.
//

#ifndef FUNCTIONAL_CALLS_H
#define FUNCTIONAL_CALLS_H
// Generally comment a module if you don't use it to reduce the flash memory

/*** Configuration for setup functions ***/

// general purpose and alternative function
#define GPIO_ENABLE

// Timer
// #define TIMER_ENABLE

/*** Configuration for Functional calling functions ***/
// Not yet built


/*** GPIO setup function ***/

#ifdef GPIO_ENABLE
    #include "gpio.h"
#endif

/*** TIMER setup function ***/

#ifdef TIMER_ENABLE
#include "timer.h"
#endif

#endif //FUNCTIONAL_CALLS_H
