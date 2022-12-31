/********************************
 * File  	:  Timer0.c
 * Date	 	:  Mar 23, 2021
 * Target	:  ATMEGA32
 * Author	:  Eng_Fawzi
 ********************************/

#include "Timer0.h"

void TIMER0_Init(void)
{
	#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL/*normal mode*/)
		TIMER0_TCCR0_REG|= TIMER0_INTERVAL_MODE;
	#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
		TIMER0_TCCR0_REG|= TIMER0_CTC_MODE;
	#elif (TIMER_OPERATION_MODE == TIMER0_MODE_FAST_PWM)
		TIMER0_TCCR0_REG|= TIMER0_PWM_FAST;
	#elif (TIMER_OPERATION_MODE == TIMER0_MODE_PWM_PHASE_CORRECT)
		TIMER0_TCCR0_REG|= TIMER0_PWM_PHASE_CORRECT;
	#else
		#error "You Shall Define Timer Operation Mode In Timer0_Cfg.h"
	#endif
}
#if ((TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL) || (TIMER_OPERATION_MODE == TIMER0_MODE_CTC))
void TIMER0_Start(Uint8 prescaler)
{
	TIMER0_TCCR0_REG |=prescaler;
}

void TIMER0_Stop(void)
{
	TIMER0_TCCR0_REG &=0xF8; // 1111 1000
}

#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL)
void TIMER0_SetPreload(Uint8 preLoadValue)
{
	TIMER0_TCNT0_REG = preLoadValue;
}
#endif

Uint8 TIMER0_GetPreload()
{
	return TIMER0_TCNT0_REG;
}

void TIMER0_EnableInterrupt(void)
{
#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL)
	Setbit(TIMER0_TIMSK_REG,TIMER0_INTERVAL_INT_ENABLE_BIT_NO);
#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
	Setbit(TIMER0_TIMSK_REG,TIMER0_CTC_INT_ENABLE_BIT_NO);
#endif
}
void TIMER0_DisableInterrupt(void)
{
#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL)
	Clearbit(TIMER0_TIMSK_REG,TIMER0_INTERVAL_INT_ENABLE_BIT_NO);
#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
	Clearbit(TIMER0_TIMSK_REG,TIMER0_CTC_INT_ENABLE_BIT_NO);
#endif
}

#if (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
void TIMER0_SetCompareValue(Uint8 compareValue)
{
	TIMER0_OCR0_REG = compareValue;
}
#endif
#endif

#if ((TIMER_OPERATION_MDOE == TIMER0_MODE_FAST_PWM) || (TIMER_OPERATION_MODE == TIMER0_MODE_PWM_PHASE_CORRECT))
void TIMER0_PWM(Uint8 freq, Uint8 dutyCycle)
{
	Uint16 result =0 ;
	result = (dutyCycle * TIMER0_TOP)/100;
	TIMER0_OCR0_REG = result;

	/*	Check for frequency then choose prescaler	*/
}
#endif

