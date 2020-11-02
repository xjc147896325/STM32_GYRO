#ifndef __DRV_TIMER_H
#define __DRV_TIMER_H

#include "stm32f4xx.h"
#include "drv_nvic.h"

void TIM2_Init(uint16_t arr, uint16_t psc);
void TIM3_Init(uint16_t arr, uint16_t psc);
void TIM4_Init(uint16_t arr, uint16_t psc);
void TIM5_Init(uint16_t arr, uint16_t psc);


#endif

