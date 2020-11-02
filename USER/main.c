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
//		uint8_t sample[4];         
//		int8_t  temp;
//		int32_t Ad7190_Data[4] = {0};
//		static int a = 0;
//		
//		

//		if((Get_ADC_flag())&&(AD7190_RDY_STATE==0))
//		{
//			drv_spi_read_write_string(sample,0,4); 
//			if((sample[3]&0x80)==0)
//			{
//				temp=(sample[3]&0x07)-4;
//				if(temp>=0)
//				{
//					#if ZERO_MODE==1
//					bias_data[temp]=((sample[0]<<16)|(sample[1]<<8)|sample[2]);
//					#else        
//					Ad7190_Data[temp]=((sample[0]<<16) | (sample[1]<<8) | sample[2])-Get_bias_data()[temp];        
//						Set_ad7190_data(Ad7190_Data);
//					  #endif
//					Set_number(temp);
//					Set_ADC_flag(2);
//					//a++;
					Serial_Send(Serial1,"time:%d\r\n",1);
					delay_ms(100);
//				}
//				else
//				{
//					Serial_Send(Serial1,"error:0x%X\r\n",sample[3]);

//					Set_ADC_flag(Get_ADC_flag()+1);
//					if(Get_ADC_flag()>=10)
//					{
//						  Set_ADC_flag(0);
//						  Serial_Send(Serial1,"Ê§°Ü£¡£¡£¡\r\n"); 
//					}       
//				}
//			}
//		}

//		if(Get_ADC_flag()==2)   
//		{      
//			#if ZERO_MODE==1
//			printf("IN%d. 0x%05X\n",number,bias_data[number]);
//			#else        
//			Voltage_Data[Get_number()]=Get_ad7190_data()[Get_number()]>>4;
//			Voltage_Data[Get_number()]=Voltage_Data[Get_number()]*REFERENCE_VOLTAGE/OPA_RES_R2*OPA_RES_R1/0xFFFFF;
//			Set_voltage_data(Voltage_Data);
//			Serial_Send(Serial1,"IN%d. 0x%X->%f\r\n",Get_number(),Get_ad7190_data()[Get_number()],Get_voltage_data()[Get_number()]/1000);
//			#endif

//			Set_ADC_flag(1);
//		}	
		//delay_ms(10);
		

//		i = Get_Beta();
//		Serial_Send(Serial1,"main\r\n%f\r\n",i);

		
		
	}
}
