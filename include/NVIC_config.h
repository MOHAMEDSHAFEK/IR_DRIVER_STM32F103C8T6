/*
 * NVIC_config.h
 *
 *  Created on: August 19, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
/*****************************************************/
#ifndef NVIC_config_H_
#define NVIC_config_H_

	/*selct from System control bolck groub and subgroub priority */
/*
#define MNVIC_GROUP_4_SUB_0 		    0x05FA0300   // 4 BIT FOR GROUP IPR -> GROUP
#define MNVIC_GROUP_3_SUB_1	 		0x05FA0400	// 3 BIT FOR GROUP IPR -> GROUP 1 bit supgroup
#define MNVIC_GROUP_2_SUB_2 			0x05FA0500	// 2 BIT FOR GROUP IPR -> GROUP 2  bits supgroup
#define MNVIC_GROUP_1_SUB_3			 0x05FA0600	// 1 BIT FOR GROUP IPR -> GROUP 3 bits supgroup
#define MNVIC_GROUP_0_SUB_4			 0x05FA0700	// 0 BIT FOR GROUP IPR -> GROUP 4 bits supgroup
*/
#define MNVIC_CROUP_SUB_DISTRIBUTION 	MNVIC_GROUP_2_SUB_2
#endif /* NVIC_config_H_ */
