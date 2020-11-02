/**
  ******************************************************************************
  * @file    init.c
  * @author  jOKERII
  * @version v1.0
  * @date    20-03-30
  * @brief   System_Init(void);
						 

  ******************************************************************************
  */

#include "init.h"




/**
  * @brief  system init
  * @param  none
  * @retval 无
  */
void System_Init(void)
{
	char s[] = "heiheihei";
	int32_t Bias_Data[4] = {0};
	
	SystemInit();
	NVIC_Priority_Init();
	SysTick_Init();
	
	USART1_Init(115200);
	
	if(AD7190_Init() == 0)
	{
		Serial_Send(Serial1,"获取不到 AD7190 !\r\n");	
		while(1)
		{
			delay_ms(1000);
			if(AD7190_Init())
			{
				break;
			}
		}
	}
	Serial_Send(Serial1,"检测到 AD7190 !\r\n");	
	
  /* AD7190四路单端采集配置 */
	AD7190_Unipolar_Multichannel_Conf();

	Bias_Data[0] = BIAS_VOLTAGE_IN1;
	Bias_Data[1] = BIAS_VOLTAGE_IN2;
	Bias_Data[2] = BIAS_VOLTAGE_IN3;
	Bias_Data[3] = BIAS_VOLTAGE_IN4;
	
	Set_ADC_flag(1);
	Set_bias_data(Bias_Data);

	USART2_Init(115200);
	TIM2_Init(8399,9);
	TIM3_Init(8399,9);
	Serial_Send(Serial1,"ready %s \r\n",&s);
	
//	drv_spi_init();
//	Laser_Init();
	LED_Init();
	
	delay_ms(500);
	
}


