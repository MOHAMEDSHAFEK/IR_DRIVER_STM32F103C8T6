/****************************************/
/*
 * NVIC_program.c

 *
 *  Created on: August 19, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
 /***************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*****************************************/
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}

	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}

	else
	{
		/* Return Error */
	}

}



void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}

	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}

	else
	{
		/* Return Error */
	}

}


void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}

	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}

	else
	{
		/* Return Error */
	}

}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}

	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}

	else
	{
		/* Return Error */
	}

}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result=0;

	if ( Copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}

	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}

	else
	{
		/* Return Error */
	}

	return Local_u8Result;

}


void MNVIC_voidInit(void)
{
	/*system control bloc core periphral */
	#define SCB_AIRCR			*((volatile u32*)(0xE000ED00+0x0C))
	SCB_AIRCR = MNVIC_CROUP_SUB_DISTRIBUTION;
}


void MNVIC_voidSetPriority( s8 Copy_s8IntID , u8 Copy_u8GroupPriorty, u8 Copy_u8SupPriorty, u32 copy_u32Group )
{
				/*0x05FA0400   3 groub and one sup*/
	u8 Local_u8Priority =Copy_u8SupPriorty|(Copy_u8GroupPriorty << ((copy_u32Group- 0x05FA0300)/256));
	/*core peripheral */
	
	/*external peripheral */   /* EXTR0 = 6 */
	if(Copy_s8IntID>=0)
	{
		NVIC_IPR[Copy_s8IntID]=Local_u8Priority<<4;
	}
	SCB_AIRCR = copy_u32Group;
}

void MNVIC_voidSetPriorityS(u8 copy_u8PeripheralIdx,u8 copy_u8Priority)
{
	if(copy_u8PeripheralIdx<60)
	{
		NVIC_IPR[copy_u8PeripheralIdx]=copy_u8Priority;
	}
	else
	{
		/*return error */
	}
}



