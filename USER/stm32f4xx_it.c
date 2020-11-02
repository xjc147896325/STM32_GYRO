/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.4.0
  * @date    04-August-2014
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
 

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
 if(E_COUNTER!=0)
	{
		E_COUNTER--;
	}
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/*****************************USART**************************/
/**
  * @brief  This function handles USART1 Handler.
  * @param  None
  * @retval None
  */
void USART1_IRQHandler(void)
{
	if(USART_GetFlagStatus(USART1, USART_IT_RXNE) != RESET);
	{
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	}
}

/**
  * @brief  This function handles USART2 Handler.
  * @param  None
  * @retval None
  */
void USART2_IRQHandler(void)
{
	if(USART_GetFlagStatus(USART2, USART_IT_RXNE) != RESET);
	{
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);
	}
}

/**
  * @brief  This function handles USART3 Handler.
  * @param  None
  * @retval None
  */
void USART3_IRQHandler(void)
{
	if(USART_GetFlagStatus(USART3, USART_IT_RXNE) != RESET);
	{
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);
	}
}

/**
  * @brief  This function handles USART6 Handler.
  * @param  None
  * @retval None
  */
void USART6_IRQHandler(void)
{
	if(USART_GetFlagStatus(USART6, USART_IT_RXNE) != RESET);
	{
		USART_ClearITPendingBit(USART6, USART_IT_RXNE);
	}
}

/*****************************TIMER**************************/

/**
* @brief 定时器2中断函数，1ms
* @param none
* @return none
*/	
void TIM2_IRQHandler(void)
{	
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)   //每隔1ms进入一次更新中断
	{	
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);      //清除标志位

//		Serial_Send(Serial1,"time:%d\r\n",2);
	
		LED_Task(LED1,500);
		
		//ADC_Queue_Updata(Get_Laser_Val()); //会死
	}
}

/**
* @brief 定时器3中断函数，5ms
* @param none
* @return none
*/	
void TIM3_IRQHandler(void)
{	
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)   //每隔5ms进入一次更新中断
	{	
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);      //清除标志位
		
		static uint8_t sample[4];         
		static int8_t  temp;
		static int32_t Ad7190_Data[4] = {0};
		static double Voltage_Data[4];

//		static int a = 0;
		
		
		//Serial_Send(Serial1,"time:%d\r\n",3);

		if((Get_ADC_flag())&&(AD7190_RDY_STATE==0))
		{
			drv_spi_read_write_string(sample,0,4); 
			if((sample[3]&0x80)==0)
			{
				temp=(sample[3]&0x07)-4;
				if(temp>=0)
				{
					#if ZERO_MODE==1
					bias_data[temp]=((sample[0]<<16)|(sample[1]<<8)|sample[2]);
					#else        
					Ad7190_Data[temp]=((sample[0]<<16) | (sample[1]<<8) | sample[2])-Get_bias_data()[temp];        
						Set_ad7190_data(Ad7190_Data);
					  #endif
					Set_number(temp);
					Set_ADC_flag(2);
					//a++;
					//Serial_Send(Serial1,"time:%d\r\n",a);
				}
				else
				{
					Serial_Send(Serial1,"error:0x%X\r\n",sample[3]);

					Set_ADC_flag(Get_ADC_flag()+1);
					if(Get_ADC_flag()>=10)
					{
						  Set_ADC_flag(0);
						  Serial_Send(Serial1,"失败！！！\r\n"); 
					}       
				}
			}
		}
		
		if(Get_ADC_flag()==2)   
		{      
			#if ZERO_MODE==1
			printf("IN%d. 0x%05X\n",number,bias_data[number]);
			#else        
			Voltage_Data[Get_number()]=Get_ad7190_data()[Get_number()]>>4;
			Voltage_Data[Get_number()]=Voltage_Data[Get_number()]*REFERENCE_VOLTAGE/OPA_RES_R2*OPA_RES_R1/0xFFFFF;
			Set_voltage_data(Voltage_Data);
			Serial_Send(Serial1,"IN%d. 0x%X->%fV\r\n",Get_number(),Get_ad7190_data()[Get_number()],Get_voltage_data()[Get_number()]/1000);
			#endif

			Set_ADC_flag(1);
		}	

	}
}



/*****************************DMA**************************/

/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
