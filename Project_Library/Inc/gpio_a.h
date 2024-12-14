//
// Created by loitr on 12/11/2024.
//

#ifndef GPIO_H
#define GPIO_H

/**************  Bit relative configuration in APB2ENR register  **************/
#define GPIOA_APB2_ENABLE            0x4     // bit 2

/**************  common register configuration for GPIO  **************/
#include "common_gpio_address.h"

// Port A
void GPIOA_Setup(int pin, int mode, int cnf);
void GPIOA_Pull_Setup(int pin, int pull_up);

#endif //GPIO_H
