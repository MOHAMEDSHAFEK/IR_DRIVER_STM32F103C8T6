/*************************************************************/
/* SYSTICK_program.c
*creat on August 28,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***************************************************/
#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"
/**********************************************/
/*Glubal function for call back*/
void (*Callback) (void)=NULL;
/*selection the mode of timer IntervalSengil or IntervalPeriodic*/
static u8 systick_mode_flag=0;

void MSTK_voidInit(void)
{
		#if CLOCK_SOURCE == AHB_8
		CLR_BIT(STK_CTRL,CLKSOURCE);
	#elif CLOCK_SOURCE == PROCESSOR_CLOCK_AHB
		SET_BIT(STK_CTRL,CLKSOURCE);
	#else
	#endif
		
		SET_BIT(STK_CTRL,ENABLE);   //Enables the counter for systic timer
}

void MSTK_voidSetBusyWait(u32 copy_u32Ticks)
{
	systick_mode_flag=2;
	STK_VAL=CLEAR_REGISTER;
	copy_u32Ticks = copy_u32Ticks*FACTOR_OF_CONVERT_NS_TO_MS;  //convert from micro  to  ms
	if(copy_u32Ticks<MAX_NUMBER_OF_LOAD_SYSTICK)
	{
		 STK_LOAD =CLEAR_REGISTER;
		 STK_LOAD = STK_LOAD|copy_u32Ticks;
		 while (1)
		 {
			 if(1==GET_BIT(STK_CTRL,COUNT_FLAG))
			 {
				 break;
			 }
		 }
		 STK_VAL=CLEAR_REGISTER;
	}
}

void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks,void (*copy_ptr)(void))
{
	systick_mode_flag=0;
	CLR_BIT(STK_CTRL,0);
	STK_VAL=CLEAR_REGISTER;
	//copy_u32Ticks = copy_u32Ticks*FACTOR_OF_CONVERT_NS_TO_MS;  //convert from micro  to  ms
	STK_LOAD =copy_u32Ticks;
	SET_BIT(STK_CTRL,ENABLE);   //Enables the counter for systic timer
   // STK_LOAD = STK_LOAD|copy_u32Ticks;
	if(copy_ptr != NULL)
	{
		Callback=copy_ptr;
	}
	SET_BIT(STK_CTRL,TICKINT);  //Enables the interrupt for systic timer
}
void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks,void (*copy_ptr)(void))
{
	systick_mode_flag=1;
	/*clear load register*/
	STK_LOAD =CLEAR_REGISTER;
	/*load value in reload register*/
	STK_VAL=CLEAR_REGISTER;
	copy_u32Ticks = copy_u32Ticks*FACTOR_OF_CONVERT_NS_TO_MS;  //convert from micro  to  ms
    STK_LOAD = STK_LOAD|copy_u32Ticks;
	if(copy_ptr != NULL)
	{
		Callback=copy_ptr;
	}
	SET_BIT(STK_CTRL,TICKINT);  //Enables the interrupt for systic timer
}


void MSTK_voidStopInterval(void)
{
	CLR_BIT(STK_CTRL,ENABLE);   //Disables the counter for systic timer
	/*clear load register*/
	STK_LOAD =CLEAR_REGISTER;
	STK_VAL=CLEAR_REGISTER;    //clear value register
}

u32 MSTK_u32GetElapsedTimer(void)
{
	u32 u8Elapsedvalue;
	u8Elapsedvalue=STK_LOAD-STK_VAL;
	/*return the diffrint btween the load register and value register*/
	return u8Elapsedvalue;
}

u32 MSTK_u32GetRemainingTimer(void)
{
	/*return the value of value register*/
	return STK_VAL;
}

void SysTick_Handler(void)
{
	if(Callback != NULL)
	{
		Callback();
		if(systick_mode_flag==0) //single mode
		{
			CLR_BIT(STK_CTRL,TICKINT);  //Enables the interrupt for systic timer
			/*clear load register*/
			STK_LOAD =CLEAR_REGISTER;
			STK_VAL=CLEAR_REGISTER;    //clear value register
		}
		if(systick_mode_flag==1)    //pridoc mode
		{
			//GET_BIT(STK_CTRL,COUNT_FLAG);
		}
	}
}
