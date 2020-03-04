#include "key.h"
#include "systick.h"
#include "LCD_5110.h"
#include "led.h"
#include "display.h"
#include "timer.h"
/*/////////////////////////////////////////////////////////////////////////////////	 
//本程序是键控源文件 
作用：按键扫描 
1.GPIO初始化
2.返回的（按键flag）值判断
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，KEY1按下
//2，KEY2按下
//3，KEY3按下 
//4，KEY4按下 WK_UP
//注意此函数有响应优先级,KEY1>KEY2>KEY3>KEY4
1.GPIO初始化
2.存放音调 节拍 播放蜂鸣曲
3.实现程序
（适合STM32F10x系列）		   
引用日期:2018/12/30
All rights reserved
********************************************************************************/

//按键初始化函数
void KEY_Init(void) //IO初始化
{ //1.使能时钟
//2.用到的GPIO口

//4.输出模式=上拉输入
//5.GPIO初始化
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(KEY_PORT_RCC, ENABLE); 	//使能GPIOC GPIOA时钟
	GPIO_InitStructure.GPIO_Pin = KEY_PINL;         //KEY123 PA567
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(KEY_PORTL, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = KEY_PINR;         //KEY4 	 PC4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(KEY_PORTR, &GPIO_InitStructure);
}


u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;															//按键按松开标志
		if(mode)key_up=1;  														//支持连按		  
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))
		//1    与  	0<-（0	 或		 0	或		0		或		 0）=0不扫描不执行
		//1    与  	1<-（1	 或		 0	或		0		或		 0）=1要扫描看是哪个键
	{
		delay_ms(8);				//去抖动 此处可能唱歌的延时去掉
		key_up=0;																			//按键按下标志	
		if(KEY1==0)return KEY1_PRES;
		else if(KEY2==0)return KEY2_PRES;
		else if(KEY3==0)return KEY3_PRES;
		else if(KEY4==0)return KEY4_PRES;
	}else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1)key_up=1; 	    
 	return 0;							//无按键按下
}

void Scan (void)
{
				u8 key;												 //一个8位单字节变量
			  key=KEY_Scan(0);				//1.按键扫描程序      支持连按  无按键按下KEY_Scan=0即key=0

		if (key)                  											//无按键按下的情况下key=0不执行下列程序
			{																							//检测到有按键按下key!=0
			switch(key)
				{
//					case KEY1_PRES:														//上一首					
//						Display_num(0);													//传送值为-1
//						break;
//					case KEY2_PRES:
//						LCD_Write_words(0,0,7,0,12);						//传送值为1
//						break;
					case KEY3_PRES:
						LED3=1;
						break;					
//					case KEY4_PRES:

//						break;
				}
			}
}
