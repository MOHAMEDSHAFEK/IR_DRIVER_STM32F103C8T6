/****************************************/
/*
 * EXTI_program.c
 *
 *  Created on: August 24, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
 /***************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*****************************************/
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

static void (*EXTI_CallBackGlobal[16])(void);

void MEXTI_voidInit( void )
{
	#if 	EXTI_LINE==EXTI_LINE0
		SET_BIT(EXTI->IMR,EXTI_LINE0);
	#elif	EXTI_LINE==EXTI_LINE1
		SET_BIT(EXTI->IMR,EXTI_LINE1);
	#elif	EXTI_LINE==EXTI_LINE2
		SET_BIT(EXTI->IMR,EXTI_LINE2);	
	#elif	EXTI_LINE==EXTI_LINE3
		SET_BIT(EXTI->IMR,EXTI_LINE3);
	#elif	EXTI_LINE==EXTI_LINE4
		SET_BIT(EXTI->IMR,EXTI_LINE4);
	#elif	EXTI_LINE==EXTI_LINE5
		SET_BIT(EXTI->IMR,EXTI_LINE5);
	#elif	EXTI_LINE==EXTI_LINE6
		SET_BIT(EXTI->IMR,EXTI_LINE6);	
	#elif	EXTI_LINE==EXTI_LINE7
		SET_BIT(EXTI->IMR,EXTI_LINE7);
	#elif	EXTI_LINE==EXTI_LINE8
		SET_BIT(EXTI->IMR,EXTI_LINE8);	
	#elif	EXTI_LINE==EXTI_LINE9
		SET_BIT(EXTI->IMR,EXTI_LINE9);
	#elif	EXTI_LINE==EXTI_LINE10
		SET_BIT(EXTI->IMR,EXTI_LINE10);	
	#elif	EXTI_LINE==EXTI_LINE11
		SET_BIT(EXTI->IMR,EXTI_LINE11);
	#elif	EXTI_LINE==EXTI_LINE12
		SET_BIT(EXTI->IMR,EXTI_LINE12);	
	#elif	EXTI_LINE==EXTI_LINE13
		SET_BIT(EXTI->IMR,EXTI_LINE13);
	#elif	EXTI_LINE==EXTI_LINE14
		SET_BIT(EXTI->IMR,EXTI_LINE14);	
	#elif	EXTI_LINE==EXTI_LINE15
		SET_BIT(EXTI->IMR,EXTI_LINE15);	
	#else 
		#error ("Wrong External Interrupt line")
	#endif
	#if 	EXTI_MODE == RISING
		SET_BIT(EXTI->RTSR, EXTI_LINE0);
	#elif 	EXTI_MODE == FALLING
		SET_BIT(EXTI->FTSR, EXTI_LINE);
	#elif 	EXTI_MODE == ON_CHANGE
		SET_BIT(EXTI->RTSR, EXTI_LINE);
		SET_BIT(EXTI->FTSR, EXTI_LINE);	
	#else
		#error "wrong mode "
	#endif	
	/*Disable interrupt*/
	//CLR_BIT(EXTI->IMR, Copy_u8Line);	
}


void MEXTI_voidSetSignalLatch( u8 copy_u8EXTILine, u8 copy_u8EXTISenseMode )
{

		switch(copy_u8EXTISenseMode)
		{
			case RISING: 				SET_BIT(EXTI->RTSR, EXTI_LINE0); 			break;
			case FALLING:			SET_BIT(EXTI->FTSR, EXTI_LINE0); 			break;
			case ON_CHANGE:	SET_BIT(EXTI->RTSR, EXTI_LINE0);
												SET_BIT(EXTI->FTSR, EXTI_LINE0);		 		break;
		}
	/*line change */

		SET_BIT(EXTI->IMR,copy_u8EXTILine);

}

void MEXTI_voidEnable( u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR, Copy_u8Line);	
}
void MEXTI_voidDisable( u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR, Copy_u8Line);
}
void MEXTI_voidSwTrigger( u8 Copy_u8Line)
{
	SET_BIT(EXTI->SWIER, Copy_u8Line);
}

void MEXIT_voidSetCallBack(u8  copy_u8InterruptNumber,void(*copyLocalPtr)(void))
{
	if(copyLocalPtr!=NULL)
	{
		EXTI_CallBackGlobal[copy_u8InterruptNumber]=copyLocalPtr;
	}
}
void EXTI0_IRQHandler(void)
{
	if (EXTI_CallBackGlobal[EXTI_LINE0]!=NULL)
	{
		EXTI_CallBackGlobal[EXTI_LINE0]();
	}
	/*clear pending bit*/
	SET_BIT(EXTI->PR,0);
}
void EXTI1_IRQHandler(void)
{
	if (EXTI_CallBackGlobal[EXTI_LINE1]!=NULL)
	{
		EXTI_CallBackGlobal[EXTI_LINE1]();
	}
	SET_BIT(EXTI->PR,1);
}
