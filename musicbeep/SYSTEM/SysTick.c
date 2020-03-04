#include "SysTick.h"
#include "misc.h"
#include "LED.h"
#include "timer.h"
u8 fac_us = 0;
u16 fac_ms = 0;

void SysTick_Init(u8 SYSCLK)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_us = SYSCLK / 8;
	fac_ms = (u16)fac_us*1000;
}

void delay_us(u32 nus)
{
	u32 temp;
	SysTick->LOAD = nus * fac_us;
	SysTick->VAL = 0;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	do{
		temp = SysTick->CTRL;
	}while((temp&0x01)&&(!(temp&(1<<16))));
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL = 0;
}
void delay_ms(u16 nms)
{
	
	u32 temp;
	SysTick->LOAD = nms * fac_ms;
	SysTick->VAL = 0;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	do{
		temp = SysTick->CTRL;
	}while((temp&0x01)&&(!(temp&(1<<16))));
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL = 0;
}
