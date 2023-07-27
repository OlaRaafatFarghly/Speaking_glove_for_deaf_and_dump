/*
 * LCD_interface.h
 *
 *  Created on: Aug 4, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

void HLCD_voidSendCommand(u8 A_u8Command);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidInit(void);
void HLCD_voidClearDisplay(void);
void HLCD_voidSendString(u8 *A_Pu8String);
void HLCD_voidGoToPosition(u8 A_u8RowNum,u8 A_u8ColNum);
void HLCD_voidDisplayNumber(u32 A_u32Number);
#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
