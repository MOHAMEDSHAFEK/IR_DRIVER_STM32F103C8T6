/*
 * AFIO_interface.h
 *
 *  Created on: August 24, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
 /******************************************/

#ifndef AFIO_interface_H_
#define AFIO_interface_H_
#include "AFIO_private.h"

#define HIGH    1
#define LOW     0
#define AFIO_ENABLE      0

/*line and mode*/
void MAFIO_voidSetEXTIConfiguration(u8 copy_u8Line, u8 copy_u8PortMap);
#endif /* AFIO_interface_H_ */
