/*
 * ADC_program.c
 *
 *  Created on: Aug 28, 2022
 *      Author: El-Sa7er
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_priivate.h"
#include "../Include/MCAL/DIO/DIO_configuration.h"

#include "../Include/MCAL/ADC/ADC_interface.h"
#include "../Include/MCAL/ADC/ADC_private.h"
#include "../Include/MCAL/ADC/ADC_configration.h"
void MADC_void_Init(void)
{
//	1-select Vref =Avcc
//	2- right adjustment
//	3-disable auto trigger
//	4-select clck/64
//	5-enable adc

////#define ADMUX_REG 0b01000000
////#define ADCSRA_REG 0b11000110
////MDIO_voidSetPortDirection(ADMUX, ADMUX_REG);
////MDIO_voidSetPortDirection(ADCSRA, ADCSRA_REG);
CLR_BIT(ADMUX,7);
SET_BIT(ADMUX,6);

CLR_BIT(ADMUX,5);

CLR_BIT(ADCSRA,5);

CLR_BIT(ADCSRA,0);
SET_BIT(ADCSRA,1);
SET_BIT(ADCSRA,2);

SET_BIT(ADCSRA,7);
}
u16 MADC_u16GetDigitalValue(u8 A_u8Channel)
{
	u16 local_u16DigitalValue=0;
	if(A_u8Channel<32)
	{
//		clear the channel 5-bits
		ADMUX &=0b11100000;
//		selsect channel
		ADMUX|=A_u8Channel;
//		start conversion
		SET_BIT(ADCSRA,6);
//		polling on ADC complete flag
		while(GET_BIT(ADCSRA,4)==0);
//		clear intterupt flag
		SET_BIT(ADCSRA,4);
//		read conversion value
		local_u16DigitalValue = ADCLH;
	}
	return local_u16DigitalValue;
}
