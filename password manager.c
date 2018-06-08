/*
 * password_manager.c
 *
 * Created: 10/29/2015 10:06:31 PM
 *  Author: wh
 */ 

#include <avr/io.h>
#include "password manager.h"
#include "StdTypes.h"
#include <util/delay.h>
void password_manager(void)
{
	
	u8 user_password[4];
	u8 i=0;
	u8 keyPressed=0;
	u8 prekeypressed=0;

	Timer_Wait1ms(10);
	for (i=0;i<=3;i++)
	{
		do
		{
			keyPressed = Key_Scan();
			_delay_ms(100);
		} while (keyPressed==prekeypressed);
		prekeypressed=keyPressed;
		
		
		
		// Wait if key still pressed
		user_password[i]=keyPressed;
		if (keyPressed >= '0' && keyPressed <= '9')
		{
			LCD_OutChar('*');
		}
		else if (keyPressed == '*' || keyPressed == '#')
		{
			LCD_Clear();
		}
	}
	
	
	for (i=0;i<=3;i++)
	{
		if (user_password[i]=='1')
		{
			UART_OutChar('1');
		}
		else if (user_password[i]=='2')
		{
			UART_OutChar('2');
		}
		else if (user_password[i]=='3')
		{
			UART_OutChar('3');
		}
		else if (user_password[i]=='4')
		{
			UART_OutChar('4');
		}
		else if (user_password[i]=='5')
		{
			UART_OutChar('5');
		}
		else if (user_password[i]=='6')
		{
			UART_OutChar('6');
		}
		else if (user_password[i]=='7')
		{
			UART_OutChar('7');
		}
		else if (user_password[i]=='8')
		{
			UART_OutChar('8');
		}
		else if(user_password[i]=='9')
		{
			UART_OutChar('9');
		}
		
	}
	
}