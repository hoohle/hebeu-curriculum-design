#ifndef __KEY_H
#define __KEY_H	 

/*/////////////////////////////////////////////////////////////////////////////////	
/本程序是KEY头文件 作用：位带操作LED灯
//KEY键控相关定义声明（适合STM32F10x系列）		   
//更正日期:2018/12/30
//All rights reserved
********************************************************************************/   	 
#include "sys.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x.h"

#define K4 PCin(4)	//PC4  
#define K1 PAin(5)	//PA5 
#define K2 PAin(6)	//PA6
#define K3 PAin(7)  //PA7*/
//左三键PA567 右一键PC4
#define KEY1  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)//读取按键1
#define KEY2  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)//读取按键2
#define KEY3  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)//读取按键3
#define KEY4  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)//读取按键4

//立个FLAG
#define KEY1_PRES 1	//KEY1按下
#define KEY2_PRES	2	//KEY2按下
#define KEY3_PRES	3	//KEY3按下
#define KEY4_PRES 4 //KEY4按下

#define KEY_PORTR GPIOC
#define KEY_PORTL GPIOA
#define KEY_PINR GPIO_Pin_4
#define KEY_PINL GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7
#define KEY_PORT_RCC RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOA
void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8);  	//按键扫描函数
void Scan(void);		//按键扫描程序
#endif
