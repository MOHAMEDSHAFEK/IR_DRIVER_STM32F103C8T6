/*
 * RCC_config.h
 *
 *  Created on: August 8, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */

#ifndef RCC_config_H_
#define RCC_config_H_
/*  OPTIONS:    RCC_HSE_CRYSTAL  0
				RCC_HSE_RC       1
				RCC-HSI          2
				RCC_PLL          3
*/
#define RCC_CLOCK_TYPE RCC_HSE_CRYSTAL

/* Options:     RCC_PLL_IN_HSI_DIV_2
                RCC_PLL_IN_HSE_DIV_2
				RCC_PLL_IN_HSE      */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT     RCC_PLL_IN_HSE_DIV_2
#endif




/* options multipliction 2 to 16 */
/* Note: drlrvy eslur only ig you have PLL as input clock source */
#define CLK_PLL					OFF 
/*  OPTIONS:  	  ON  	  1
				  OFF     0
*/
#if CLK_PLL==ON
/*  OPTIONS:  	  ON  	  1
				  OFF     0
*/
#define PLL_SOURCE				EXT
/*  OPTIONS:  	  EXT 	         1
				  INT_DIV_BY_2 	 0
*/
#define PLL_EXT_PRESCALER		PLL_HSE_NO_DIV
/*  OPTIONS:    PLL_HSE_NO_DIV		0
				PLL_HSE_DIV_BY_2    1
*/
#define PLL_PRESCALER			PLL_PS_9
/*  OPTIONS:    PLL_PS_2	0
				PLL_PS_3	1
				PLL_PS_4	2
				PLL_PS_5	3
				PLL_PS_6	4
				PLL_PS_7	5
				PLL_PS_8	6
				PLL_PS_9	7
				PLL_PS_10	8
				PLL_PS_11	9
				PLL_PS_12	10
				PLL_PS_13	11
				PLL_PS_14	12
				PLL_PS_15	13
				PLL_PS_16	14
				PLL_PS_16	15			
*/
#endif



#endif /* RCC_config_H_ */