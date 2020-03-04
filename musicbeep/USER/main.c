#include "stm32f10x.h"

/*
  ******************************************************************************
  * @文件   (file)   musicbeep/USER/main.c
  * @作者 (author)   通信1621
  * @版本(version)   工程模板：基于固件库 STM32F10x_StdPeriph_Lib_V3.5.0
  * @日期   (date)   30-December-2018
  * @简介  (brief)   这里是主函数，所有程序的入口函数main函数
  *          This file provides template。。。。
  ******************************************************************************

*/


#include "SysTick.h"
//#include "beep.h"
#include "led.h"
#include "key.h"
#include "display.h"
#include "LCD_5110.h"
#include "timer.h"

 

 int main(void)
 {	
 SysTick_Init(72);               //延时函数啥的存放在这儿
			char id=0;									//默认播放单号
			char max=6;										//定义最大歌曲数目
	 //	u8 key;										//一个8位单字节变量
	LED_Init();										 //LED灯初始化
//	BEEP_Init();									 //蜂鸣器初始化
	KEY_Init();                    //KEY按键初始化
	Display_Init();                //LED数码管初始化
	LCD_Init();                    //LCD屏幕初始化

	/*****************欢迎界面***********************/	
	LCD_clear();//液晶清屏	
  LCD_draw_bmp_pixel(0,0,0,84,48);                  //欢迎您使用    	
	 Display_Start();																	//数码管开机界面

   while(KEY4==1);  	 					  //1.直到按下启动键
//	 LCD_clear();                                     //液晶清屏

//	TIM_Configuration();                            //定时器配置 
//	TIM_NVIC_Configuration();                       //中断配置

 /*******************开机后************************/
// 		TIM2_IRQHandler();
//Music_Quiet();
	 while(1)
	{ 
		
		if(KEY4==0){ 						
			LCD_Start();														//液晶显示
			Display_Clear();												//数码管清屏
			LED_Start();
			LCD_clear();
		}	
//			if(KEY3==0)
//			{				
//				PAout(2)=0;
//				
//			}
						
		if(id>max) id=0;											//如果歌曲越界归零
			if(id<0) id=max;
			Music_Play(id);
						
//		Scan();
		
//LCD_clear();		
		if(KEY2==0) id+=1;
		else	if(KEY1==0) id-=1;
//		else	if(KEY3==0) 	Music_Quiet();//中了个 (￢︿￢☆)断去你奶奶的腿
		else id+=1;

	} //while循环结束


	
}//主函数结束
 
 
 