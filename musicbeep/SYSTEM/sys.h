#ifndef __SYSTEM__H
#define __SYSTEM__H
#include "stm32f10x.h"
//调用日期：12.31.2018
//功能简介：位带操作,实现51类似的GPIO控制功能            IO口操作宏定义
//具体实现思想,参考<<CM3权威指南>>第五章(87页~92页).

//0,不支持ucos
//1,支持ucos
#define SYSTEM_SUPPORT_OS		0		//定义系统文件夹是否支持UCOS																	    	 


//定义位带地址宏
#define BITBAND(addr,bitnum) ((addr&0xF0000000) + 0x02000000 + ((addr&0x000FFFFF)<<5) + (bitnum<<2))
#define MEM_ADDR(addr) *((volatile unsigned long *)(addr))
#define BIT_ADDR(addr,bitnum) MEM_ADDR(BITBAND(addr,bitnum))
//IO口地址映射
//数据输出寄存器地址
#define GPIOA_ODR_Addr	(GPIOA_BASE + 12)
#define GPIOB_ODR_Addr	(GPIOB_BASE + 12)
#define GPIOC_ODR_Addr	(GPIOC_BASE + 12)
#define GPIOD_ODR_Addr	(GPIOD_BASE + 12)
#define GPIOE_ODR_Addr	(GPIOE_BASE + 12)
#define GPIOF_ODR_Addr	(GPIOF_BASE + 12)
#define GPIOG_ODR_Addr	(GPIOG_BASE + 12)
//数据输入寄存器地址 //IO口地址映射
#define GPIOA_IDR_Addr	(GPIOA_BASE + 8)
#define GPIOB_IDR_Addr	(GPIOB_BASE + 8)
#define GPIOC_IDR_Addr	(GPIOC_BASE + 8)
#define GPIOD_IDR_Addr	(GPIOD_BASE + 8)
#define GPIOE_IDR_Addr	(GPIOE_BASE + 8)
#define GPIOF_IDR_Addr	(GPIOF_BASE + 8)
#define GPIOG_IDR_Addr	(GPIOG_BASE + 8)

//IO口操作,只对单一的IO口!
//确保n的值小于16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出 
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //输出 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //输入

//以下为汇编函数
void WFI_SET(void);		//执行WFI指令
void INTX_DISABLE(void);//关闭所有中断
void INTX_ENABLE(void);	//开启所有中断
void MSR_MSP(u32 addr);	//设置堆栈地址

#endif
