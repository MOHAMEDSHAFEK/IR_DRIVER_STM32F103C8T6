/*
 * RCC_interface.h
 *
 *  Created on: August 8, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */

#ifndef RCC_interface_H_
#define RCC_interface_H_

#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2

void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerID );
void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerID );

void RCC_voidInitSysClock(void); //use configurations in RCC_config.h 


#endif /* RCC_interface_H_ */
