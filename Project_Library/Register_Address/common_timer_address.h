//
// Created by loitr on 12/14/2024.
//

#ifndef COMMON_TIMER_ADDRESS_H
#define COMMON_TIMER_ADDRESS_H

/*************************** Time-based unit register **************************/
#define RESET_TIM_CNT           0x0000U   // reset value of Counter register
#define RESET_TIM_PSC           0x0000U   // reset value of Prescaler register
#define RESET_TIM_ARR           0xFFFFU   // reset value of Auto-Reload register

/****************** Bit configuration of Control register 1 (CR1) *****************/
#define CR_COUNT_ENR            0x1       // bit 0 relative to this register
#define CR_DIR                  0x8       // bit 4 relative to this register

/************ Bit configuration of Slave Mode Control register (SMCR) *************/
#define SMCR_RESET              0x0000U   // reset register

// Slave mode selection in SMCR register (bit [2:0])
#define SMS_RESET               0x7       // Reset bits

#define SMS_DISABLE             0x0       // Slave mode disabled
// #define SMS_ENCODER1            0x1       // Encoder mode 1
// #define SMS_ENCODER2            0x2       // Encoder mode 2
// #define SMS_ENCODER3            0x3       // Encoder mode 3
// #define SMS_RESET               0x4       // Reset mode
// #define SMS_GATED               0x5       // Gated mode
// #define SMS_TRIGGER             0x6       // Trigger mode
#define SMS_EXT_CLOCK           0x7       // External Clock mode

// Trigger Selection (bit [6:4])
#define TS_RESET                0x7       // Reset bits

// #define TS_INT_TR0              0x0       // Internal Trigger 0
// #define TS_INT_TR1              0x1       // Internal Trigger 1
// #define TS_INT_TR2              0x2       // Internal Trigger 2
// #define TS_INT_TR3              0x3       // Internal Trigger 3
// #define TS_TI1_EDGE_DETECOR     0x4       // TI1 Edge Detector
// #define TS_FILT_TIM_INPUT1      0x5       // Filtered Timer Input 1
// #define TS_FILT_TIM_INPUT2      0x6       // Filtered Timer Input 2
#define TS_EXTER_TRIG           0x7       // External Trigger input

/************** Bit configuration of Interrupt Enable register (DIER) *************/
#define DIER_UP_ENR             0x1       // bit 0 relative to this register

/**************** capture/compare mode register 1 (or 2) (CCMRx) ******************/
#define CCMR_RESET              0x0000    // reset the register
#define CCMR_OCM_MODE_1         0x6       // Mode 1 for PWM (''''|....)
#define CCMR_OCM_MODE_2         0x7       // Mode 2 for PWM (....|'''')

/******************* capture/compare enable register (CCERx) **********************/
#define CCER_RESET              0xFFFF    // reset the register
#define CCER_CH1_ENR            0x1       // Enable for Channel 1
#define CCER_CH2_ENR            0x10      // Enable for Channel 2
#define CCER_CH3_ENR            0x100     // Enable for Channel 3
#define CCER_CH4_ENR            0x1000    // Enable for Channel 4

#endif //COMMON_TIMER_ADDRESS_H
