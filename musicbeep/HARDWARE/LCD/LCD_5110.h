#ifndef __LCD5110_H
#define __LCD5110_H	 

/*/////////////////////////////////////////////////////////////////////////////////	
/本程序是LCD头文件
//LCD液晶显示器相关定义声明和相关程序说明（适合STM32F10x系列）	
硬件型号：Nokia（诺基亚）5110
84*48的点阵 下高位 纵向扫描
//更正日期:2018/01/04
//All rights reserved
********************************************************************************/   	 
#include "sys.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "display.h"

//#define SET_LCD_RST	LCD_RST=1	//置位
#define SET_LCD_RST	 GPIO_SetBits(GPIOC,GPIO_Pin_5)//置位  C5置1
#define CLR_LCD_RST  GPIO_ResetBits(GPIOC,GPIO_Pin_5)//C5置0

#define SET_LCD_CE	GPIO_SetBits(GPIOB,GPIO_Pin_0)//置位   B0
#define CLR_LCD_CE	GPIO_ResetBits(GPIOB,GPIO_Pin_0) 

#define SET_LCD_DC	GPIO_SetBits(GPIOB,GPIO_Pin_1)//置位   B1
#define CLR_LCD_DC	GPIO_ResetBits(GPIOB,GPIO_Pin_1) 

#define SET_SDIN	GPIO_SetBits(GPIOB,GPIO_Pin_10)//置位   B10
#define CLR_SDIN	GPIO_ResetBits(GPIOB,GPIO_Pin_10) 

#define SET_SCLK	GPIO_SetBits(GPIOB,GPIO_Pin_11)//置位   B11
#define CLR_SCLK	GPIO_ResetBits(GPIOB,GPIO_Pin_11) 

  /**********************************************************************
* 函数名称：LCD_write_byte()
* 函数功能：写一个字节
* 入口参数：data,要写入的字节;command:0为命令,1为数据
* 出口参数：无
* 修改人  ：BDC
* 修改时间：2011/08/04
***********************************************************************/
void LCD_write_byte( unsigned char data, unsigned char command)    ;

   /**********************************************************************
* 函数名称：LCD_clear()		
* 函数功能：液晶清屏
* 入口参数：无
* 出口参数：无
* 修改人  ：BDC
* 修改时间：2011/08/04
**********************************************************************/
void LCD_clear(void)    ;

/**********************************************************************
* 函数名称：LCD_Init()		
* 函数功能：初始化nokia5110
* 入口参数：无
* 出口参数：无
* 修改人  ：BDC
* 修改时间：2011/08/04
**********************************************************************/
void LCD_Init(void)  ;

  
  /**********************************************************************
* 函数名称：LCD_set_XY()
* 函数功能：光标定位x行y列
* 入口参数：X,Y   x行y列
* 出口参数：无
* 修改人  ：BDC
* 修改时间：2011/08/04
**********************************************************************/
void LCD_set_XY( unsigned char X,  unsigned char Y)        ;

 /***********************************************************************
* 函数名称：LCD_write_char()
* 函数功能：写入1个字符
* 入口参数：c   要写入的数据
* 出口参数：无
* 修改人  ：BDC
* 修改时间：2011/08/04
**********************************************************************/
void LCD_write_char( unsigned char c)   ;

  /***********************************************************************
* 函数名称：LCD_Write_Char()
* 函数功能：写入1个字符
* 入口参数：X:行;Y:列;asc:要写入的数据
* 出口参数：无
* 修改人  ：BDC
* 修改时间：2011/08/04
**********************************************************************/
void LCD_Write_Char( unsigned char X, unsigned char Y, unsigned char asc)         ;

/***********************************************************************
* 函数名称：LCD_Write_Num()
* 函数功能：显示变亮
* 入口参数：X:行;Y:列;num:变量;N:要显示的变量的位数
* 出口参数：无
* 修改人  ：BDC
* 修改时间：2011/08/04
**********************************************************************/
void LCD_Write_Num( unsigned char X, unsigned char Y ,   int num, unsigned char N)    ;

/***********************************************************************
* 函数名称LCD_write_english_string()
* 函数功能：写英文字符串
* 入口参数：X,Y,*S------x行y列*s为英文字符串
* 出口参数：无
* 修改人  ：BDC
* 修改时间：2011/08/04
***********************************************************************/
void LCD_write_english_string( unsigned char X, unsigned char Y,unsigned char *s)  ;

 

/*********************************************************** 
*函数名称：LCD_vertical_bar
*函数功能：画竖线
*入口参数：X：位图绘制的起始Xertical_bar竖线内容
*
*出口参数：无 
*修改人  ：
*修改时间：
*备 注： 
***********************************************************/

void LCD_vertical_bar(unsigned char X , unsigned char *vertical_bar);
/*********************************************************** 
*函数名称：LCD_Vertical_Bar
*函数功能：画竖线  动态
*入口参数:   X:横坐标；high:需要的高度
*
*出口参数：无 
*修改人  ：
*修改时间：
*备 注： 
***********************************************************/


//void LCD_Vertical_Bar(unsigned char X,unsigned char high )  ;
void LCD_Vertical_Bar(unsigned char X,unsigned int high,unsigned int  line);

/*********************************************************** 
*函数名称：LCD_Write_cn
*函数功能：写中文
*入口参数: row:列 page:页 dd:字符 
*
*出口参数：无 
*修改人  ：
*修改时间：
*备 注： 
***********************************************************/
//void LCD_Paodao(void) ;


/***********************************************************
函数名称：LCD_draw_bmp_pixel
函数功能：位图绘制函数
入口参数：X、Y    ：位图绘制的起始X、Y坐标；
          *map    ：位图点阵数据；
          Pix_x   ：位图像素（长）
          Pix_y   ：位图像素（宽）
出口参数：无
备 注：
***********************************************************/
void LCD_draw_bmp_pixel(unsigned char X,unsigned char Y,unsigned char *map, unsigned char Pix_x,unsigned char Pix_y);
void LCD_draw_bmp_pause(unsigned char X,unsigned char Y,unsigned char *map, unsigned char Pix_x,unsigned char Pix_y);

void LCD_Write_cn(unsigned char row, unsigned char page,unsigned char c); 

void LCD_Write_words(unsigned char row,unsigned char page,unsigned char n,unsigned char c,unsigned word_spacing);  //n 代表写几个字，row，列，page，页，c 代表从字库表的第几个开始,word_spacing代表字间距，推荐为14

void Lcd_Display(u32 date);
void LCD_Start(void);//LCD液晶开机显示程序
void LCD_ID(char n);//显示播放曲目名程序
#endif

