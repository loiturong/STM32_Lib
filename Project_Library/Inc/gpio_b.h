//
// Created by loitr on 12/14/2024.
//

#ifndef GPIO_B_H
#define GPIO_B_H

/**************  Bit relative configuration in APB2ENR register  **************/
#define GPIOB_APB2_ENABLE            0x8     // bit 3 (count from 0)

/**************  common register configuration for GPIO  **************/
#include "common_gpio_address.h"

// Port B
void GPIOB_Setup(int pin, int mode, int cnf);
void GPIOB_Pull_Setup(int pin, int pull_up);

#endif //GPIO_B_H
