/**
  ******************************************************************************
  * @file    drv_time.c
  * @author  xjc
  * @version v1.0
  * @date    20-09-17
  * @brief   中断函数在it内
							TIM2_Init()
  ******************************************************************************
  */
#include "drv_timer.h"

void TIM2_Init(uint16_t arr, uint16_t psc)   //1ms 8399,9
{
	//arr自动重装载值
	//psc预分频值
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef         NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //定时器2时钟使能

	/*定时器2初始化*/
	TIM_TimeBaseStructure.TIM_Period = arr;              //设置重载值
	TIM_TimeBaseStructure.TIM_Prescaler = psc;           //设置分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     //设置分频因子
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //递增计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);             //将结构参数用于初始化定时器2

	TIM_ITConfig(TIM2, TIM_IT_Update,ENABLE );           //使能定时器2更新中断

	/*设置中断参数*/
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;            //定时器2中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = TIMER2_PreemptionPriority;  //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = TIMER2_SubPriority;         //响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;            //使能中断通道
	NVIC_Init(&NVIC_InitStructure);                            //初始化中断
	TIM_Cmd(TIM2, ENABLE);  //使能定时器

}

void TIM3_Init(uint16_t arr, uint16_t psc)   //1ms 8399,9
{
	//arr自动重装载值
	//psc预分频值
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef         NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //定时器2时钟使能

	/*定时器2初始化*/
	TIM_TimeBaseStructure.TIM_Period = arr;              //设置重载值
	TIM_TimeBaseStructure.TIM_Prescaler = psc;           //设置分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     //设置分频因子
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //递增计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);             //将结构参数用于初始化定时器2

	TIM_ITConfig(TIM3, TIM_IT_Update,ENABLE );           //使能定时器2更新中断

	/*设置中断参数*/
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;            //定时器2中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = TIMER3_PreemptionPriority;  //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = TIMER3_SubPriority;         //响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;            //使能中断通道
	NVIC_Init(&NVIC_InitStructure);                            //初始化中断
	TIM_Cmd(TIM3, ENABLE);  //使能定时器

}

