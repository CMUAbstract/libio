#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

extern volatile uint32_t pin1_status __attribute__((section(".pin1_status")));
extern volatile uint32_t pin2_status __attribute__((section(".pin2_status")));
extern volatile uint32_t pin3_status __attribute__((section(".pin3_status")));
extern volatile uint32_t pin4_status __attribute__((section(".pin4_status")));

#endif