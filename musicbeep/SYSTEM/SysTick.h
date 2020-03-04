#ifndef __SysTick__H
#define __SysTick__H
#include "stm32f10x.h"

void SysTick_Init(u8 SYSCLK);
void delay_us(u32 nus);
void delay_ms(u16 nms);

#endif

