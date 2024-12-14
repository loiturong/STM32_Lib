//
// Created by loitr on 12/14/2024.
//

#ifndef COMMON_GPIO_ADDRESS_H
#define COMMON_GPIO_ADDRESS_H

/**************  Configuration and Mode in CRL and CRH register  **************/

  // Reset mode
#define GPIO_RESET_MODE         0xF     // reset mode for register
  // Input mode and it's configuration
#define MODE_Input              0b00    // This bit is the reset state of Mc

#define CNF_Analog              0b00
#define CNF_Floating            0b01
#define CNF_Input_Pull          0b10    // If Pull up is set up, a bit of ODR correspond to the pin need to be configured

  // Output mode configuration
#define MODE_Output_10MHz       0b01
#define MODE_Output_2MHz        0b10
#define MODE_Output_50MHz       0b11

#define CNF_GP_PUSH_PULL        0b00    // setup with ODR, but we can ignore it
#define CNF_GP_OPEN_DRAIN       0b01    // setup with ODR, but we can ignore it
#define CNF_AF_PUSH_PULL        0b10
#define CNF_AF_OPEN_DRAIN       0b11

#endif //COMMON_GPIO_ADDRESS_H
