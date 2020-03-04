#include "display.h"
#include "systick.h"

/*/////////////////////////////////////////////////////////////////////////////////	 
//本程序是显示器源文件 
作用：显示HELLO 显示曲目123
1.GPIO初始化
2.GPIO位带操作LED数码管
3.实现程序只要在每首歌播放的时候引用程序就行啦
(适合STM32F10x系列)	   
更正日期:2018/12/30
All rights reserved
********************************************************************************/
void Display_Init(){   /*数码管从左->右管脚对应*/ /*A8 A11 A12 C7 C8 C9*/
	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( EDG_PORT_RCC, ENABLE ); 					//1.使能GPIOC时钟
	GPIO_InitStructure.GPIO_Pin = EDG_PINL|EDG_PINR;					//2.用到的GPIO口
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					//3.总线速度
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;					//4.输出模式=推挽
	GPIO_Init(EDG_PORTL, &GPIO_InitStructure);								  //5.GPIO初始化
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					//3.总线速度
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;					//4.输出模式=推挽
	GPIO_Init(EDG_PORTR, &GPIO_InitStructure);								  //5.GPIO初始化
 		
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15 ;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
}

void CD4534_clear(void)
{
	A=0,B=0,C=0,D=0;
}

void Display_Start(void)
	{
		
		l1=1,l2=1,l3=1,R1=1;R2=1;R3=1;
		B=1,C=1;
	}
	
void Display_Pause(void)
	{
		l1=1,l2=1,l3=1,R1=1;R2=1;R3=1;
		CD4534_clear();
	}
	
void Display_Clear(void)
{
	l1=0,l2=0,l3=0,R1=0;R2=0;R3=0;
	A=0,B=0,C=0,D=0;
}


void Display_num(u8 num)
{
	switch(num){
		case 0:
			Display_Clear();			
		break;
		
		case 1:
			Display_Clear();
		R3=1,A=1;
		break;
		
		case 2:
			Display_Clear();
		R3=1,B=1;
		break;
		
		case 3:
			Display_Clear();
		R3=1,A=1,B=1;
		break;
		
		case 4:
			Display_Clear();
		R3=1,C=1;
		break;
		
		case 5:
			Display_Clear();
		R3=1,A=1,C=1;
		break;
		
		case 6:
			Display_Clear();
		R3=1,B=1,C=1;
		break;
		
		case 7:
			Display_Clear();
		R3=1,A=1,B=1,C=1;
		break;
		
		case 8:
			Display_Clear();
		R3=1,D=1;
		break;
		
		case 9:
			Display_Clear();
		R3=1,A=1,D=1;
		break;
		}
}

