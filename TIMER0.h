/*
 * Timer0.h
 *
 * Created: 9/23/2015 4:55:03 PM
 *  Author: alaa
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "STDTypes.h"

void Timer_Init (void);
void Timer_Wait (u16 cycles);
void Timer_Wait1ms (u16 delay);



#endif /* TIMER0_H_ */