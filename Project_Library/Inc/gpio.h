//
// Created by loitr on 12/11/2024.
//

#ifndef GPIO_H
#define GPIO_H
// Port A
void GPIOA_Setup(int pin, int cnf, int mode);
void GPIOA_Pull_Setup(int pin, int pull_up);
// Port B
void GPIOB_Setup(int pin, int cnf, int mode);
void GPIOB_Pull_Setup(int pin, int pull_up);

#endif //GPIO_H
