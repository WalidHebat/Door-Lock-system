/*
 * slave.c
 *
 * Created: 10/26/2015 10:33:03 PM
 *  Author: wh
 */ 


#include <avr/io.h>
#include "UART.h"
#include "UART_CFG.h"
#include "eeprom.h"
#include "StdTypes.h"
#include <util/delay.h>
#include "pwm.h"
#include "LCD.h"
int main(void)
{   u8 main_password[4]="1234";
    u16 address=0x0000;
	u8 received_password[4];
	u8 reading=0;
	u8 i=0;
	u8 f=0;
	DDRA|=1<<1;
    LCD_Init();
    LCD_GoToXY(0, 0);	
	UART_Init ();
	for (i=0;i<=3;i++)
	{
		Eeprom_Write (address, main_password[i]);
		address++;
	}
	address=0x0000;
	while(1)
    {
        //TODO:: Please write your application code 		
		
		for (i=0;i<=3;i++)
		{
			 received_password[i]=UART_InChar();
		}
		for (i=0;i<=3;i++)
		{
			reading=Eeprom_Read (address);
			address++;
			if (received_password[i]==reading)
			{
				f++;
			}
		}
				
		if (f==4)
		{
			UART_OutChar('t');
            LCD_OutString("The Temperature is :");
            out_temp_lcd();
			Pwm_Init();
			Pwm_Duty(255*5/100);
			_delay_ms(1000);
			Pwm_Duty(1/100);			
	        while(f=4)
			{
				PORTA|=1<<1;
			    _delay_ms(1500);
				out_temp_lcd();
			}

		}
		else
		{
			 address=0x0000;
			 received_password[4];
			 reading=0;
			 i=0;
			 f=0;
		UART_OutChar('f');
		PORTA&=~0x01;
		}
		
    }
}