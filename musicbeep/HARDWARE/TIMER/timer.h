#ifndef __TIM2_H
#define __TIM2_H

/*/////////////////////////////////////////////////////////////////////////////////
/本程序是定时器TIM2头文件 作用：短接PA2至蜂鸣器口PC6以实现PWM波控制蜂鸣器
//TIM2定时器相关定义声明（适合STM32F10x系列）
//更正日期:2018/12/30
//All rights reserved
********************************************************************************/
#include "sys.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"
#include "LED.h"
#include "key.h"
#include "LCD_5110.h"


#define  proport  	10000 					//Tclk/(psc+1)=72000000/(7199+1)
#define  P0					0//休止符
#define  L1       ((proport/131)-1)//低调　do 的周期根据Tout= ((arr+1)*(psc+1))/Tclk推出arr值就是本句define定义的值，Tout为音调频率131Hz的倒数，Tclk=72MHz
#define  L2       ((proport/147)-1)//低调　re 的周期
#define  L3       ((proport/165)-1)//低调　mi 的周期
#define  L4       ((proport/176)-1)//低调　fa 的周期
#define  L5       ((proport/196)-1)//低调　sol的周期
#define  L6       ((proport/220)-1)//低调　la 的周期
#define  L7       ((proport/247)-1)//低调　si 的周期
#define  A1				((proport/139)-1)//升1
#define  A2				((proport/156)-1)//升2
#define  A4       ((proport/185)-1)//升4
#define  A5       ((proport/208)-1)//升5
#define  A6				((proport/233)-1)//升6


#define  M1       ((proport/262)-1)//中调　do 的周期
#define  M2       ((proport/294)-1)//中调　re 的周期
#define  M3       ((proport/330)-1)//中调　mi 的周期 
#define  M4       ((proport/349)-1)//中调　fa 的周期
#define  M5       ((proport/392)-1)//中调　sol的周期
#define  M6       ((proport/440)-1)//中调　la 的周期
#define  M7       ((proport/494)-1)//中调　si 的周期
#define  B1				((proport/277)-1)//
#define  B2				((proport/311)-1)//
#define  B4       ((proport/370)-1)//
#define  B5       ((proport/416)-1)//
#define  B6				((proport/466)-1)//

#define  H1       ((proport/523)-1)//高调　do 的周期
#define  H2       ((proport/587)-1)//高调　re 的周期
#define  H3       ((proport/659)-1)//高调　mi 的周期
#define  H4       ((proport/698)-1)//高调　fa 的周期
#define  H5       ((proport/784)-1)//高调　sol的周期
#define  H6       ((proport/880)-1)//高调　la 的周期
#define  H7       ((proport/988)-1)//高调　si 的周期
#define  C1				((proport/555)-1)//
#define  C2				((proport/623)-1)//
#define  C4       ((proport/740)-1)//
#define  C5       ((proport/831)-1)//
#define  C6				((proport/933)-1)//
//#define	csb



void Timer2_Init(u16 Period);
void Music_Play(char c);//按号唱歌程序
void TIM2_IRQHandler(void);

void Music_Quiet(void);//闭嘴程序
#endif
