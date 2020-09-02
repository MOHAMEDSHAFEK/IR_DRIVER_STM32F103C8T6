/*
 * main.c
 *
 *  Created on: Mar 17, 2020
 *      Author: shfek
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
//#include "AFIO_interface.h"
#include "EXTI_interface.h"

#include "SYSTICK_interface.h"
void voidPlay(void);
volatile u32 u32FramData[50]={0};
volatile u8 u8EdgeCounter =0;
volatile u8 u8Data =0;
volatile u8 u8StartFlag =0;
void voidGetFram(void);
void voidTackAction(void);
//void EXT1_func(void);
void main(void)
{
	/*RCC Initialize*/
	 RCC_voidInitSysClock();
	// RCC_voidEnableClock(RCC_APB2,AFIO_ENABLE);
	 RCC_voidEnableClock(RCC_APB2,GPIOA_ENABLE);
	 /*PINA0 as a input dirction*/
	 MGPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_FLOATING);
	 MGPIO_voidSetPinValue(GPIOA,PIN0,HIGH);
	 /*PINA2 as a output*/
	 MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_voidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);
	 /*callback for external interrupt*/
	 MEXIT_voidSetCallBack(EXTI_LINE0,voidGetFram);
	 /*set the sens mode*/
	 MEXTI_voidSetSignalLatch(EXTI_LINE0,FALLING);
	 /*set the priority*/
	 //MNVIC_voidSetPriorityS(6,1);
	 /*Enable EXTR0 from NVIC*/
	 MNVIC_voidEnableInterrupt(6);
	 /*enable external interrupt*/
	// MEXTI_VoidEnable(EXTI_LINE0);
	 /*Enable systick/ */
	 MSTK_voidInit();
	// MGPIO_ViodSetPinValue(GPIOA,PIN2,HIGH);
	while(1)
	{

	}
}

/*
 * u32 u32FramData[50]={0};
u8 u8EdgeCounter =0;
u8 u8StartFlag =0;
 * */

void voidPlay(void)
{
	volatile u8 k=5;
	switch(u8Data)
		{
			case 28:
				 MGPIO_voidSetPinValue(GPIOA,PIN2,LOW);
				 MGPIO_voidSetPinValue(GPIOA,PIN3,LOW);
				 MGPIO_voidSetPinValue(GPIOA,PIN1,HIGH);  break;

			case 86:
				  MGPIO_voidSetPinValue(GPIOA,PIN1,LOW);
				  MGPIO_voidSetPinValue(GPIOA,PIN3,LOW);
				  MGPIO_voidSetPinValue(GPIOA,PIN2,HIGH);  break;
			case 31:
				MGPIO_voidSetPinValue(GPIOA,PIN2,LOW);
			   MGPIO_voidSetPinValue(GPIOA,PIN1,LOW);
			   MGPIO_voidSetPinValue(GPIOA,PIN3,HIGH);  break;
			case 87:
				while(k>0)
				{
							 MGPIO_voidSetPinValue(GPIOA,PIN2,LOW);
							 MGPIO_voidSetPinValue(GPIOA,PIN3,LOW);
							 MGPIO_voidSetPinValue(GPIOA,PIN1,HIGH);
							  MSTK_voidSetBusyWait(600);
							  MGPIO_voidSetPinValue(GPIOA,PIN1,LOW);
							  MGPIO_voidSetPinValue(GPIOA,PIN3,LOW);
							   MGPIO_voidSetPinValue(GPIOA,PIN2,HIGH);
							   MSTK_voidSetBusyWait(600);
							   MGPIO_voidSetPinValue(GPIOA,PIN2,LOW);
							   MGPIO_voidSetPinValue(GPIOA,PIN1,LOW);
							   MGPIO_voidSetPinValue(GPIOA,PIN3,HIGH);
							   MSTK_voidSetBusyWait(600);
							   k--;
				}
																										break;
			case 8: MGPIO_voidSetPinValue(GPIOA,PIN1,LOW);
						 MGPIO_voidSetPinValue(GPIOA,PIN2,LOW);
						 MGPIO_voidSetPinValue(GPIOA,PIN3,LOW);
																										break;


		}
}
void voidGetFram(void)
{
	if(u8StartFlag==0)
	{
		/*start timer*/
		MSTK_voidSetIntervalSingle(1000000,voidTackAction);
		u8StartFlag=1;
	}
	else
	{
		u32FramData[u8EdgeCounter]= MSTK_u32GetElapsedTimer();
		MSTK_voidSetIntervalSingle(1000000,voidTackAction);
		u8EdgeCounter++;
	}
}

void voidTackAction(void)
{
	u8 i;
	u8Data=0;
	if((u32FramData[0] >= 10000)&&(u32FramData[0] <= 14000))
	{
		for(i=0;i<8;i++)
		{
			if((u32FramData[17+i] >= 2000)&&(u32FramData[17+i] <= 2300))
			{
				SET_BIT(u8Data,i);
			}
			else
			{
				CLR_BIT(u8Data,i);
			}
		}
		voidPlay();
	}
		else
		{

		}

	u8StartFlag=0;
	u32FramData[0]=0;
	u8EdgeCounter=0;
}

