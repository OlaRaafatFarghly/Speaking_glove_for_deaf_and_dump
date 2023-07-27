/*
 * main.c
 *
 *  Created on: Aug 3, 2022
 *      Author: abdelrahmanhossam
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_priivate.h"
#include "../Include/MCAL/DIO/DIO_configuration.h"

#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/LCD/LCD_private.h"
#include "../include/HAL/LCD/LCD_configurations.h"

#include "../Include/MCAL/ADC/ADC_interface.h"
#include "../Include/MCAL/ADC/ADC_private.h"
#include "../Include/MCAL/ADC/ADC_configration.h"

#include <util/delay.h>
#define F_CPU 8000000UL

void main(void)
{
	u16 digital_1=0;
	u16 analog_1=0;
	u16 digital_2=0;
	u16 analog_2=0;
    MDIO_voidInit();
    HLCD_voidInit();
    MADC_void_Init();
    while (1)
   {
//    	digital_1=MADC_u16GetDigitalValue(ADC0);
//    	analog_1=(u16)((digital_1*25000UL)/1024);
//    	_delay_ms(1000);
    	digital_2=MADC_u16GetDigitalValue(0);
    	analog_2=(u16)((digital_2*25000UL)/1024);

//	HLCD_voidClearDisplay();
//	HLCD_voidGoToPosition(LCD_ROW_ONE,12 );
//	HLCD_voidDisplayNumber(analog_1);
//	_delay_ms(1000);
	HLCD_voidGoToPosition(LCD_ROW_TWO, 12);
	HLCD_voidDisplayNumber(analog_2);
	_delay_ms(1000);
	HLCD_voidClearDisplay();


    }
}

