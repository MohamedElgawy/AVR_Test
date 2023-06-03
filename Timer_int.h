/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 2/4/2023                        */
/*                      Module : TIMER_int                       */
/*                      Layer  : MCAL                            */
/*                      Version:  1.0                            */
/*****************************************************************/

#ifndef _TIMER0_INT_H
#define _TIMER0_INT_H


void TIMER0_voidInit(void);

void TIMER0_void_SetTimerReg(u8 Copy_u8Val);

void TIMER0_voidSetCompareVal(u8 Copy_u8Val);

void TIMER0_voidEnableOVInt(void);

void TIMER0_voidDisableOVInt(void);

void TIMER0_voidEnableCTCInt(void);

void TIMER0_voidDisableCTCInt(void);

void TIMER0_voidSetOVCallBack(void (*Copy_ptr) (void) );

void TIMER0_voidSetCTCCallBack(void (*Copy_ptr) (void) );


#endif