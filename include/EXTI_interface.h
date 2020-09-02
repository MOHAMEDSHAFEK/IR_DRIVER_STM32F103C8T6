/*
 * EXTI_interface.h
 *
 *  Created on: August 24, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
 /******************************************/

#ifndef EXTI_interface_H_
#define EXTI_interface_H_
#include "EXTI_private.h"

#define HIGH    1
#define LOW     0


/*line and mode*/
void MEXTI_voidInit( void );
void MEXTI_voidSetSignalLatch( u8 copy_u8EXTILine, u8 copy_u8EXTISenseMode );
void MEXTI_voidEnable( u8 Copy_u8EXTILine);
void MEXTI_voidDisable( u8 Copy_u8EXTILine);
void MEXTI_voidSwTrigger( u8 Copy_u8Line);

void MEXIT_voidSetCallBack(u8  copy_u8InterruptNumber,void(*copyLocalPtr)(void));
#endif /* EXTI_interface_H_ */
