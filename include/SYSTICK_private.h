/*************************************************************/
/* SYSTICK_private_h
*creat on August 25,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#ifndef SYSTICK_private_h_
#define SYSTICK_private_h_


/*STK_CTRL SysTick control and status register*/
#define  STK_CTRL 	*((volatile u32*)0xE000E010)

/*STK_LOAD SysTick reload value register
Bits 31:24 Reserved, must be kept cleared. */
#define STK_LOAD    *((volatile u32*)0xE000E014)

/*STK_VAL SysTick current value register 
Bits 31:24 Reserved, must be kept cleared.*/
#define STK_VAL     *((volatile u32*)0xE000E018)

/*SysTick calibration value register (STK_CALIB)
Reset value: 0x0002328
Required privilege: Privileged
The CALIB register indicates the SysTick calibration properties.*/
#define STK_CALIB   *((volatile u32*)0xE000E01C)


/*STK_CTRL SysTick control and status register*/
#define COUNT_FLAG   16    /*
									
							Bit 16 COUNTFLAG:
							Returns 1 if timer counted to 0 since last time this was read.		
									*/
#define CLKSOURCE    2    /*
							Bit 2 CLKSOURCE: Clock source selection
							Selects the clock source.
							0: AHB/8
							1: Processor clock (AHB)	
									*/
#define TICKINT      1    /*
							SysTick exception request enable
							0: Counting down to zero does not assert the SysTick exception request
							1: Counting down to zero to asserts the SysTick exception request.
							Note: Software can use COUNTFLAG to determine if SysTick has ever counted to zero.	
									*/
#define ENABLE       0   /*
							Counter enable
							Enables the counter. When ENABLE is set to 1, the counter loads the RELOAD value from the
							LOAD register and then counts down. On reaching 0, it sets the COUNTFLAG to 1 and
							optionally asserts the SysTick depending on the value of TICKINT. It then loads the RELOAD
							value again, and begins counting.
							0: Counter disabled
							1: Counter enabled	
									*/
#endif /*SYSTICK_private_h*/