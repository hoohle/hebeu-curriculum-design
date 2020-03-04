#ifndef __BEEP__H
#define __BEEP__H
//无他惯用写法防止写了没用又一堆麻烦事 含义是如果没有声明则声明
/*/////////////////////////////////////////////////////////////////////////////////	 
//本程序是BEEP头文件 作用：位带操作蜂鸣器
//蜂鸣器相关定义声明（适合STM32F10x系列）		   
//更正日期:2018/12/30
//All rights reserved
******************************************************************************* */
#include "sys.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

//定义GPIOC的位地址变量宏，位输入宏，输出宏
#define PBeep PCout(6)

#define BEEP_PORT	GPIOC
#define BEEP_PIN	GPIO_Pin_6
#define BEEP_PORT_RCC RCC_APB2Periph_GPIOC
void BEEP_Init(void);
void Sound(u16 frq);
void play(void);
#endif

