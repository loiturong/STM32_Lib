//
// Created by loitr on 12/10/2024.
//

#ifndef VAL_H
#define VAL_H


/*  Relative position of APB1ENR register  */
#define TIM2_ENABLE 0x01        // Bit 0 of the APB1ENR register


/*  Relative position of APB2ENR register  */
#define GPIOA_ENABLE 0x4       // (1<<2)
#define GPIOB_ENABLE 0x8       // (1<<3)
#define GPIOC_ENABLE 0x10      // (1<<4)
#define GPIOD_ENABLE 0x20      // (1<<5)
#define GPIOE_ENABLE 0x40      // (1<<6)
// #define GPIOF_ENABLE 0x80   // (1<<7)
// #define GPIOG_ENABLE 0x100  // (1<<8)
#define TIM1_ENABLE 0x400      // (1<<11)



/*  Configuration and Mode in CRL and CRH register  */
// Input mode and it's configuration
#define MODE_Input      0b00    // This bit is the reset state of Mc

#define CNF_Analog      0b00
#define CNF_Floating    0b01
#define CNF_Input_Pull  0b10    // If Pull up is set up, a bit of ODR correspond to the pin need to be configured

// Output mode configuration
#define MODE_Output_10MHz   0b01
#define MODE_Output_2MHz    0b10
#define MODE_Output_50MHz   0b11

#define CNF_GP_PUSH_PULL    0b00    // setup with ODR, but we can ignore it
#define CNF_GP_OPEN_DRAIN   0b01    // setup with ODR, but we can ignore it
#define CNF_AF_PUSH_PULL    0b10
#define CNF_AF_OPEN_DRAIN   0b11

#endif //VAL_H
