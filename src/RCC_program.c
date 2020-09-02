/*
 * RCC_program.h
 *
 *  Created on: August 8, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidEnableClock(u8 copy_u8BusId,u8 copy_u8PerId)
{
	if (copy_u8PerId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,copy_u8PerId );  break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,copy_u8PerId );  break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,copy_u8PerId );  break;
			//default       : /* Return Error */                    break;
		}
	}
	else
	{
		/*Return Error  data valdition */
	}
	
}
void RCC_voidDisableClock(u8 copy_u8BusId,u8 copy_u8PerId)
{
	if (copy_u8PerId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,copy_u8PerId );  break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,copy_u8PerId );  break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,copy_u8PerId );  break;
			//default       : /* Return Error */                    break;
		}
	}
	else
	{
		/*Return Error  data valdition */
	}
	
}
void RCC_voidInitSysClock(void)
{
 
	#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR  =0x00010000;  /*Enable HSE with no pypass CRYSTAL*/
		RCC_CFGR=0x00000001;
	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR  =0x00050000;  /*Enable HSE with pypass RC*/
		RCC_CFGR=0x00000001;
	#elif   RCC_CLOCK_TYPE == RCC-HSI	
		RCC_CR	=0x00000081;  /*Enable HSI + 0 tremaing */
		RCC_CFGR=0x00000001;
	#elif RCC_CLOCK_TYPE == RCC_PLL
		#if PLL_SOURCE == EXT
			SET_BIT(RCC_CFGR,PLL_SRC);

			#if PLL_EXT_PRESCALER == PLL_HSE_NO_DIV
				CLR_BIT(RCC_CFGR,PLL_XTPRE);
			#elif PLL_EXT_PRESCALER == PLL_HSE_DIV_BY_2
				SET_BIT(RCC_CFGR,PLL_XTPRE);
			#endif
		#elif PLL_SOURCE == INT_DIV_BY_2
			CLR_BIT(RCC_CFGR,PLL_SRC);
		#endif
		/* choose PLL PRESCALER  */
		RCC_CFGR = (RCC_CFGR & 0xffc3ffff ) | (PLL_PRESCALER<<PLLMUL) ;
		/* turn ON PLL as the last thing */
		SET_BIT(RCC_CR,PLL_ON);
		#if CLK_PLL == OFF
		CLR_BIT(RCC_CR,PLL_ON);
		#endif
		/* choose cpu clock source  */	
		RCC_CFGR = (RCC_CFGR & 0xfffffffc) | (CPU_CLK_SOURCE) ;  
	#else
		#error("you chose wrong clock type")
	#endif 
}