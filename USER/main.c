/**
  ******************************************************************************
  * @file    main.c
  * @author  jOKERII
  * @version v1.0
  * @date    20-03-31
  * @brief   
  ******************************************************************************
  */
#include "main.h"

int main()
{	
//	double i = 0;
//	double Voltage_Data[4];
	
	System_Init();
	
	//GPIO_Format_Init(GPIOC,GPIO_Pin_3,GPIO_Mode_OUT,GPIO_OType_PP,GPIO_PuPd_UP,GPIO_Speed_100MHz);
	
	while(1)
	{
		Set_Pwm2(TIM4,300);
		Set_Pwm1(TIM14,200);
		
		
	}
}
