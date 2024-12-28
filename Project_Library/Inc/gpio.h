//
// Created by loitr on 12/28/2024.
//

#ifndef GPIO_H
#define GPIO_H

/**************  Bit relative configuration in APB2ENR register  **************/
#define GPIOA_APB2_ENABLE            0x4     // bit 2
#define GPIOB_APB2_ENABLE            0x8     // bit 3 (count from 0)

/**************  common register configuration for GPIO  **************/
#include "common_gpio_address.h"

/*** GPIO setup ***/

void GPIOA_Setup(int pin, int mode, int cnf);
void GPIOA_Pull_Setup(int pin, int pull_up);

void GPIOB_Setup(int pin, int mode, int cnf);
void GPIOB_Pull_Setup(int pin, int pull_up);

#endif //GPIO_H
