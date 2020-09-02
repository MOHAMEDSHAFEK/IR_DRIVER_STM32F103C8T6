/*
 * NVIC_interface.h
 *
 *  Created on: August 19, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
 /******************************************/

#ifndef NVIC_interface_H_
#define NVIC_interface_H_

#define HIGH    1
#define LOW     0

void MNVIC_voidEnableInterrupt( u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt( u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag( u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag( u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag( u8 Copy_u8IntNumber);

void MNVIC_voidSetPriorityS(u8 copy_u8PeripheralIdx,u8 copy_u8Priority);
void MNVIC_voidSetPriority( s8 Copy_s8IntID , u8 Copy_u8GroupPriorty, u8 Copy_u8SupPriorty, u32 copy_u32Group );

void MNVIC_voidInit(void);
#endif /* NVIC_interface_H_ */
