/*************************************************************/
/* SYSTICK_interface.h
*creat on August 25,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#ifndef SYSTICK_interface_c_
#define SYSTICK_interface_c_
//void (*Callback) (void)

#define  AHB_8 									0
#define  PROCESSOR_CLOCK_AHB				    1
#define CLEAR_REGISTER 							0X00000000
#define MAX_NUMBER_OF_LOAD_SYSTICK     			16777216
#define FACTOR_OF_CONVERT_NS_TO_MS      		1000
/*Apply clock chice fron configuration file
Disable SysTick intirrupt 
Disable SysTick*/
void MSTK_voidInit(void);

void MSTK_voidSetBusyWait(u32 copy_u32Ticks);

void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks,void (*copy_ptr)(void));
	/*
{
	load_reg =copy_u32Ticks
	//Enable of enterrupt 
	callbak = copy_ptr;
}
*/
/*
void SysTick_Handler(void)
{
	Callback();
}
*/
/*
main()
-----
MSTK_voidSetIntervalSingle(10000,func1)
MSTK_voidSetIntervalSingle(20000,func2)

void func(void)
{
	/*code
}
*/

void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks,void (*copy_ptr)(void));

void MSTK_voidStopInterval(void);

u32 MSTK_u32GetElapsedTimer(void);

u32 MSTK_u32GetRemainingTimer(void);


#endif  /*SYSTICK_interface_c_*/