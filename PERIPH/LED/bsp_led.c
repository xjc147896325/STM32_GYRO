/**
  ******************************************************************************
  * @file    led.c
  * @author  jOKERII
  * @version v1.1
  * @date    20-10-10
  * @brief   LED_Init();
			 void LED_Task(LED_Typedef LEDx)

  ******************************************************************************
  */
	
#include "bsp_led.h"

void LED_Init(void)
{
	GPIO_Format_Init(GPIOC,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3,\
					GPIO_Mode_OUT,GPIO_OType_PP,GPIO_PuPd_UP,GPIO_Speed_100MHz);
	
	GPIO_SetBits(GPIOC,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3); 
}

void LED_Task(LED_Typedef LEDx, uint32_t interval)
{
	static uint16_t i = 0, Flag = 0;
	if(i >= interval)
	{
		if(Flag)
		{
			GPIO_ResetBits(GPIOC,LEDx); 
			Flag = 0;
		}
		else
		{
			GPIO_SetBits(GPIOC,LEDx); 
			Flag = 1;
		}
		i = 0;
	}
	i++;
}
