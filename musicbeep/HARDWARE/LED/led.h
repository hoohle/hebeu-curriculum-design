#ifndef __LED_H
#define __LED_H

/*/////////////////////////////////////////////////////////////////////////////////	 
/本程序是LED头文件 作用：位带操作LED灯
//LED灯相关定义声明（适合STM32F10x系列）		   
//更正日期:2018/12/30
//All rights reserved
********************************************************************************/

#include "sys.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "timer.h"

//定义GPIOB(6789)A(01)的位地址变量宏，位输入宏，输出宏
#define LED1 PBout(6) // PB6	
#define LED2 PBout(7) // PB7	
#define LED3 PBout(8) // PB8	
#define LED4 PBout(9) // PB9	
#define LED5 PAout(0)	// PA0
#define LED6 PAout(1) // PA1

#define LED_PORTL GPIOB
#define LED_PORTR GPIOA
#define LED_PINL GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9
#define LED_PINR GPIO_Pin_0|GPIO_Pin_1
#define LED_PORT_RCC RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA
	 
	 
	 
void LED_Init(void);			//led初始化程序
void LED_Start(void);			//LED开机程序
void LED_Pause(void);	 		//LED暂停
void LED_hlhs(int c);			//花里胡哨灯
void LED_Q(void);					//流水7调灯





#endif


