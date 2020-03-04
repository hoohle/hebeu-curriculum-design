#ifndef __SYSTEM__H
#define __SYSTEM__H
#include "stm32f10x.h"
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
//数据输入寄存器地址
#define GPIOA_IDR_Addr	(GPIOA_BASE + 12)
#define GPIOB_IDR_Addr	(GPIOB_BASE + 12)
#define GPIOC_IDR_Addr	(GPIOC_BASE + 12)
#define GPIOD_IDR_Addr	(GPIOD_BASE + 12)
#define GPIOE_IDR_Addr	(GPIOE_BASE + 12)
#define GPIOF_IDR_Addr	(GPIOF_BASE + 12)
#define GPIOG_IDR_Addr	(GPIOG_BASE + 12)
#endif

