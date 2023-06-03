/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 2/4/2023                        */
/*                      Module : TIMER_prog                      */
/*                      Layer  : MCAL                            */
/*                      Version:  1.0                            */
/*****************************************************************/

#include "../../SERVICE/STD_types.h"
#include "../../SERVICE/BIT_math.h"
#include "Timer_int.h"
#include "Timer_priv.h"
#include "Timer_config.h"

static void (*TIMER0_OV_CallBack) (void);
static void (*TIMER0_CTC_CallBack) (void) ;

void TIMER0_voidInit(void)
{
	/* Select timer mode    */
	#if TIMER0_MODE ==  TIMER0_NORMAL      // time over flow mode
		CLEAR_BIT(TCCR0 ,TCCR0_WGM00);
		CLEAR_BIT(TCCR0 ,TCCR0_WGM01);
	
	#elif TIMER0_MODE == TIMER0_CTC        // clear time on compare mode
		CLEAR_BIT(TCCR0 ,TCCR0_WGM00);
		SET_BIT(TCCR0 ,TCCR0_WGM01);
		
	#elif TIMER0_MODE == TIMER0_FAST_PWM   // Fast PWM  mode
		SET_BIT(TCCR0 , TCCR0_WGM00);
		SET_BIT(TCCR0 , TCCR0_WGM01);
		
	#elif TIMER0_MODE == TIMER0_PHASE_PWM   // Phase correct PWM  mode
		SET_BIT(TCCR0 , TCCR0_WGM00);
		CLEAR_BIT(TCCR0 , TCCR0_WGM01);
	#endif
	
	
	/* Set Prescaler Clock Select  */
	#if TIMER0_PRESCALER == TIMER0_DIV_BY_1 
		SET_BIT(TCCR0 , TCCR0_CS00);
		CLEAR_BIT(TCCR0 , TCCR0_CS01);
		CLEAR_BIT(TCCR0 , TCCR0_CS02);
		
	#elif TIMER0_PRESCALER == TIMER0_DIV_BY_8 
		CLEAR_BIT(TCCR0 , TCCR0_CS00);
		SET_BIT(TCCR0 , TCCR0_CS01);
		CLEAR_BIT(TCCR0 , TCCR0_CS02);
		
	#elif TIMER0_PRESCALER == TIMER0_DIV_BY_64 
		SET_BIT(TCCR0 , TCCR0_CS00);
		SET_BIT(TCCR0 , TCCR0_CS01);
		CLEAR_BIT(TCCR0 , TCCR0_CS02);
		
	#elif TIMER0_PRESCALER == TIMER0_DIV_BY_256 
		CLEAR_BIT(TCCR0 , TCCR0_CS00);
		CLEAR_BIT(TCCR0 , TCCR0_CS01);
		SET_BIT(TCCR0 , TCCR0_CS02);
		
	#elif TIMER0_PRESCALER == TIMER0_DIV_BY_1024  
		SET_BIT(TCCR0 , TCCR0_CS00);
		CLEAR_BIT(TCCR0 , TCCR0_CS01);
		SET_BIT(TCCR0 , TCCR0_CS02);
	#endif
	
	
	/*   Action event on ISR       */
	#if TIMER0_COM_EVENT == TIMER0_NO_ACTION 
		CLEAR_BIT(TCCR0 , TCCR0_COM00);
		CLEAR_BIT(TCCR0 , TCCR0_COM01);	
	#elif TIMER0_COM_EVENT == TIMER0_TOGGLE 
		SET_BIT(TCCR0 , TCCR0_COM00)
		CLEAR_BIT(TCCR0 , TCCR0_COM01);
	#elif TIMER0_COM_EVENT ==  TIMER0_NON_INVERTED   // or Clear on compare  CTC mode or normal
		CLEAR_BIT(TCCR0 , TCCR0_COM00);
		SET_BIT(TCCR0 , TCCR0_COM01);
	#elif TIMER0_COM_EVENT ==  TIMER0_INVERTED   // or set on compare  CTC mode or normal
		SET_BIT(TCCR0 , TCCR0_COM00);
		SET_BIT(TCCR0 , TCCR0_COM01);
	#endif
	
	/*Disable Interrupts*/
	CLEAR_BIT(TIMSK , TIMSK_TOIE0);	
	CLEAR_BIT(TIMSK , TIMSK_OCIE0);
	/*CLEAR FLAGS*/
	SET_BIT(TIFR , TIFR_TOV0);	
	SET_BIT(TIFR , TIFR_OCF0);
	/*Clear register*/
	TCNT0 = 0 ;
	OCR0 = 0 ;
}

void TIMER0_voidSetTimerReg(u8 Copy_u8Val)
{
	TCNT0 = Copy_u8Val ;
}

void TIMER0_voidSetCompareVal(u8 Copy_u8Val)
{
	OCR0 = Copy_u8Val ;
}

void TIMER0_voidEnableOVInt(void)
{
	SET_BIT(TIMSK , TIMSK_TOIE0);                   // for enable interrupt overflow  mode
}

void TIMER0_voidDisableOVInt(void)
{
	CLEAR_BIT(TIMSK , TIMSK_TOIE0);
}

void TIMER0_voidEnableCTCInt(void)
{
	SET_BIT(TIMSK , TIMSK_OCIE0);
}

void TIMER0_voidDisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , TIMSK_OCIE0);
}

void TIMER0_voidSetOVCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER0_OV_CallBack = Copy_ptr ;
}

void TIMER0_voidSetCTCCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER0_CTC_CallBack = Copy_ptr ;
	
}

void __vector_11(void) __attribute__((signal)); // for avr gcc
void __vector_11(void)
{
	
	TIMER0_OV_CallBack();
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	TIMER0_CTC_CallBack();
}


