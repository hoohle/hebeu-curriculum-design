#ifndef __SCREEN__H
#define __SCREEN__H

/*/////////////////////////////////////////////////////////////////////////////////	 
//本程序是屏幕头文件 作用：位带操作LED数码管
//LED数码管相关定义声明（适合STM32F10x系列）
硬件型号：LED共阴3位八段数码管 XDSM320361D3B
数量：2个
驱动芯片：CD4534BE四七译码器
//更正日期:2018/12/31
//All rights reserved
******************************************************************************* */
#include "sys.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

//定义GPIOA（8、11、12）C（7、8、9）的位地址变量宏，位输入宏，输出宏
#define l1 PAout(8)
#define l2 PAout(11)
#define l3 PAout(12)
#define R1 PCout(7)
#define R2 PCout(8)
#define R3 PCout(9)
#define A	 PBout(12)  //	
#define B	 PBout(13)  //	
#define C  PBout(14)  //
#define D  PBout(15)  //

#define EDG_PORTL GPIOA
#define EDG_PORTR GPIOC
#define EDG_PINL GPIO_Pin_8|GPIO_Pin_11|GPIO_Pin_12
#define EDG_PINR GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9
#define EDG_PORT_RCC RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC
void Display_Init(void);//显示初始化
void Display_Clear(void);//数码管灭灯程序
void CD4534_clear(void);//译码器清屏程序

void Display_Start(void);//开机显示程序
void Display_Pause(void);//暂停显示程序
void Display_num(u8 num);//显示数字程序

#endif

