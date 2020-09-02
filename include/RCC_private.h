/*
 * RCC_private.h
 *
 *  Created on: August 8, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
/************************************************************************/
#ifndef RCC_private_H_
#define RCC_private_H_
/* Clock type */
#define RCC_HSE_CRYSTAL 0
#define RCC_HSE_RC		1
#define RCC-HSI			2
#define RCC_PLL			3
/* PLL Option */
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE		  2

/*System Control */
#define ENABLE    1
#define DISABLE   0
#define ON  	  1
#define OFF       0

/* EXTERNAL CLK types */
#define RC 		  1
#define XTAL	  0

/* PLL source options */
#define EXT 	         1
#define INT_DIV_BY_2 	 0

/* PLL PRESCALER Values */
#define PLL_PS_2	0
#define PLL_PS_3	1
#define PLL_PS_4	2
#define PLL_PS_5	3
#define PLL_PS_6	4
#define PLL_PS_7	5
#define PLL_PS_8	6
#define PLL_PS_9	7
#define PLL_PS_10	8
#define PLL_PS_11	9
#define PLL_PS_12	10
#define PLL_PS_13	11
#define PLL_PS_14	12
#define PLL_PS_15	13
#define PLL_PS_16	14
#define PLL_PS_16	15

/* PLL HSE half value option */
#define PLL_HSE_NO_DIV		0
#define PLL_HSE_DIV_BY_2	1

/* CPU CLOCK SOURCE OPTIONS */
#define CPU_CLK_PLL			2
#define CPU_CLK_XTAL		1
#define	CPU_CLK_INT			0

//RCC_CFGR bits
#define PLL_SRC     16
#define PLL_XTPRE   17
#define PLLMUL		18
#define SW			0
#define SWS			2


/*Register Definitions */
#define RCC_CR         *((volatile u32*)0x40021000) //chosing clck in processor
#define RCC_CFGR       *((volatile u32*)0x40021004) //chosing clck in processor
#define RCC_CIR        *((volatile u32*)0x40021008)
#define RCC_APP2RSTR   *((volatile u32*)0x4002100c)
#define RCC_APP1RSTR   *((volatile u32*)0x40021010)
#define RCC_AHBENR     *((volatile u32*)0x40021014) //choce the clock in prapheral 
#define RCC_APB2ENR    *((volatile u32*)0x40021018) //choce the clock in prapheral (enable and disable )
#define RCC_APB1ENR    *((volatile u32*)0x4002101c) //choce the clock in prapheral 
#define RCC_BDCR       *((volatile u32*)0x40021020)
#define RCC_CSR        *((volatile u32*)0x40021024)



#endif /* RCC_private_H_ */