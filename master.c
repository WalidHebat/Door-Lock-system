/*
 * beta_project.c
 *
 * Created: 10/26/2015 10:29:57 PM
 *  Author: wh
 */ 


#include <avr/io.h>
#include "UART.h"
#include "UART_CFG.h"
#include "KeyPad.h"
#include "LCD.h"
#include "Timer0.h"
#include "StdTypes.h"
#include <util/delay.h>


int main(void)
{
    u8 user_password[4];
    u8 i=0;			
    u8 keyPressed=0;
    u8 prekeypressed=0;	
//  Dio_Init(DIO_Config);
    UART_Init ();
    Key_Init();
//  Timer_Init();
    LCD_Init();
    LCD_GoToXY(0, 0);
    LCD_OutString("Enter your password: ");	
    u8 check='t';
	while(1)
   {
        //TODO:: Please write your application code 
	    for(i=0;i<=1;i++)                //first trial without delay
		{password_manager();}
		check=UART_InChar();
		if(check=='t')
		{
			LCD_Clear();
			LCD_OutString("WELCOME");
		}
		 else
		{
			LCD_Clear();
			LCD_OutString("PLEASE TRY AGAIN");
			_delay_ms(2000);
			LCD_Clear();
			check='t';
			LCD_OutString("Enter your password: ");	
			for(i=0;i<=1;i++)              //second trial without delay
	    	{password_manager();}
			check=UART_InChar();
			}if(check=='t')///////////////////////////
			{
				LCD_Clear();
				LCD_OutString("WELCOME");
			}
			else
			{
				LCD_Clear();
				LCD_OutString("Please Wait for 5 seconds");
				_delay_ms(3000);
				LCD_Clear();
				LCD_OutString("PLEASE TRY AGAIN");
				_delay_ms(1000);
				LCD_Clear();
				check='t';
				LCD_OutString("Enter your password: ");	
				for(i=0;i<=1;i++)              // delay 5 sec and then third trial with 
     			{password_manager();}
				check=UART_InChar();
				}if(check=='t')/////////////////////////
				{
					LCD_Clear();
					LCD_OutString("WELCOME");
				}
						
			else
			{
				LCD_Clear();
				LCD_OutString("PLEASE TRY AGAIN");
				_delay_ms(1000);
				LCD_Clear();
				check='t';
				LCD_OutString("Enter your password: ");
				for(i=0;i<=1;i++)              //fourth trial without delay
		    	{password_manager();}
				check=UART_InChar();
				}if(check=='t')////////////////////////
				{
					LCD_Clear();
					LCD_OutString("WELCOME");
				}
			
			else
			{
				LCD_Clear();
				LCD_OutString("Please Wait for 10 seconds");
				_delay_ms(3000);
				LCD_Clear();
				LCD_OutString("PLEASE TRY AGAIN");
				_delay_ms(1000);
				LCD_Clear();
				check='t';
				LCD_OutString("Enter your password: ");
				for(i=0;i<=1;i++)              //delay 10 sec and then fifth trial
		    	{password_manager();}
				check=UART_InChar();
			 
				}if(check=='t')//////////////////****************
				{
					LCD_Clear();
					LCD_OutString("WELCOME");
				}
					
			else
			{
				LCD_Clear();
				LCD_OutString("PLEASE TRY AGAIN");
				_delay_ms(2000);
				LCD_Clear();
				check='t';
				LCD_OutString("Enter your password: ");
				for(i=0;i<=1;i++)              //sixth trial without delay
			    {password_manager();}
				check=UART_InChar();
				}if(check=='t')/////////////////****************
				{
					LCD_Clear();
					LCD_OutString("WELCOME");
				}
			else
			{
				LCD_Clear();
				LCD_OutString("PLEASE TRY AGAIN LATER");
				_delay_ms(3000);
				OutCmd(0x08);
			
							
		}	   
	}			
}