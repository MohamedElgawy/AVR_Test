/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 2/4/2023                        */
/*                      Module : TIMER_private                   */
/*                      Layer  : MCAL                            */
/*                      Version:  1.0                            */
/*****************************************************************/


#ifndef _TIMER0_PRIV
#define _TIMER0_PRIV

#define TIMSK      (*(volatile u8 * )(0x59))  // Timer/Counter Interrupt Mask Register
#define OCR0       (*(volatile u8 * )(0x5C))  // Output Compare Register
#define TCCR0      (*(volatile u8 * )(0x53))  // Timer0/Counter0 Control Register 
#define TCNT0      (*(volatile u8 * )(0x52))  // Timer/Counter Register   the compare match on the following timer clock
#define TIFR       (*(volatile u8 * )(0x58))  // Timer/Counter Interrupt Flag Register



#define TIMER0_NORMAL 		    1
#define TIMER0_CTC 			    2
#define TIMER0_FAST_PWM 	    3
#define TIMER0_PHASE_PWM 	    4

#define TIMER0_DIV_BY_1			1
#define TIMER0_DIV_BY_8			5
#define TIMER0_DIV_BY_64		8
#define TIMER0_DIV_BY_256		10
#define TIMER0_DIV_BY_1024		15


#define TIMER0_NO_ACTION	   100
#define TIMER0_TOGGLE		   12
#define TIMER0_SET			   20
#define TIMER0_CLEAR		   25

#define TIMER0_INVERTED        1
#define TIMER0_NON_INVERTED    2

/* TCCR0 Register pins   */
#define TCCR0_FOC0            7 // Force Output Compare
#define TCCR0_WGM00           6 // Waveform Generation Mode
#define TCCR0_COM01           5 // Compare Output Mode, non-PWM Mode
#define TCCR0_COM00           4 // Compare Output Mode, non-PWM Mode
#define TCCR0_WGM01           3 // Waveform Generation Mode
#define TCCR0_CS02            2 // Clock Select 
#define TCCR0_CS01            1 // Clock Select
#define TCCR0_CS00            0 // Clock Select

/* TIMSK Register pins   */
#define TIMSK_OCIE0           1 // Timer/Counter0 Output Compare Match Interrupt Enable
#define TIMSK_TOIE0           0 // Timer/Counter0 Overflow Interrupt Enable

/* TIFR Register pins   */
#define TIFR_OCF0             1 // Output Compare Flag 0
#define TIFR_TOV0             0 // Timer/Counter0 Overflow Flag


#endif
