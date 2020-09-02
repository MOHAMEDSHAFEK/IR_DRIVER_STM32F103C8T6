/***********************************************************************/
/*
 * AFIO_private.h
 *
 *  Created on: August 24, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
/************************************************************************/
#ifndef AFIO_private_H_
#define AFIO_private_H_


typedef struct {
	u32 EVCR;
	u32 MAPR;
	u32 EXTICR[4];
	u32 MAPR2;	
	
}AFIO_t;


#define AFIO ((volatile AFIO_t *)0x40010000)

		
#define AFIO_LINE0    0
#define AFIO_LINE1    1
#define AFIO_LINE2    2
#define AFIO_LINE3    3
#define AFIO_LINE4    4
#define AFIO_LINE5    5
#define AFIO_LINE6    6
#define AFIO_LINE7    7
#define AFIO_LINE8    8
#define AFIO_LINE9    9
#define AFIO_LINE10   10
#define AFIO_LINE11   11
#define AFIO_LINE12   12
#define AFIO_LINE13   13
#define AFIO_LINE14   14
#define AFIO_LINE15   15

		

#endif /* AFIO_private_H_ */
