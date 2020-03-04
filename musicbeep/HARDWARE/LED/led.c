#include "led.h"
#include "systick.h"
#include "display.h"
/*/////////////////////////////////////////////////////////////////////////////////	 
本程序是LED源文件 
作用：两种模式　一种播放的时候流水模式　一种暂停的时候只亮LED1（PB6） ps（扩展）:可用灯来表明状态或者检测故障
1.GPIO初始化
2.GPIO位带操作控制LED灯
3.实现程序
（适合STM32F10x系列）		   
更正日期:2018/12/31
All rights reserved
********************************************************************************/

void LED_Init(void)
{//1.使能时钟
//2.用到的GPIO口
//3.总线速度
//4.输出模式=推挽
//5.GPIO初始化
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(LED_PORT_RCC, ENABLE); 	//使能GPIOB GPIOA时钟
	GPIO_InitStructure.GPIO_Pin = LED_PINL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED_PORTL, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = LED_PINR;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED_PORTR, &GPIO_InitStructure);
}

void LED_Q(void)
{
	LED1=!LED1;
//	LED1=!LED1;

	LED2=!LED2;
//	LED2=!LED2;

	LED3=!LED3;
//	LED3=!LED3;

	LED4=!LED4;
//	LED4=!LED4;

	LED5=!LED5;
//	LED5=!LED5;

	LED6=!LED6;
//	LED6=!LED6;	
}

void LED_Start(void)
{	
	LED1=1;
	delay_ms(100);
	LED1=0;

	LED2=1;
	delay_ms(100);
	LED2=0;

	LED3=1;
	delay_ms(100);
	LED3=0;

	LED4=1;
	delay_ms(100);
	LED4=0;

	LED5=1;
	delay_ms(100);
	LED5=0;

	LED6=1;
	delay_ms(100);
	LED6=0;
	
}
	

void LED_Pause(void)
{
	LED6=1;
}

void LED_hlhs(int c)
{
switch(c)
{
	case M1: case L1: case H1:
		LED1=!LED1;Display_Clear(),l1=1;A=1;			break;
	case M2: case L2: case H2:
		LED2=!LED2;Display_Clear(),l1=1;B=1; 		break;		
	case M3: case L3: case H3:
		LED3=!LED3;Display_Clear(),l1=1;A=1,B=1;	break;
	case M4: case L4: case H4:
		LED4=!LED4;Display_Clear(),l1=1;C=1;			break;
	case M5: case L5: case H5:
		LED5=!LED5;Display_Clear(),l1=1;A=1,C=1;	break;
	case M6: case L6:		case H6:
		LED6=!LED6;Display_Clear(),l1=1;B=1,C=1;	break;
	case M7: 	case L7:	case H7:
		LED_Q();Display_Clear(),l1=1;A=1,B=1,C=1; break;
	
}
}	
