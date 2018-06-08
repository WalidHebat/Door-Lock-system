/*
 * KeyPad.c
 * Software interface for a matrix keypad 3 columns x 4 rows
 * Created: 9/23/2015 2:30:32 AM
 *  Author: alaa
 */ 

#include <avr/io.h>
#include "KeyPad.h"
#include "StdTypes.h"
typedef const struct{
	u8 direction;
	const u8 keycode[4];
} RowType;

static const RowType ScanTab[5] = 
{	// Direction		KeyCode
	{ 0x10,			"123" }, // row 3
	{ 0x20,			"456" }, // row 2
	{ 0x40,			"789" }, // row 1
	{ 0x80,			"*0#" }, // row 0
	{ 0x00,			"   " }
};

// KeyPad on PORTC
// Input: none
// Output: none
void Key_Init (void) {
	DDRC = 0xF0;		// PC2-PC0 are inputs (Columns)
						// PC7-PC4 are out (Rows)
	PORTC &= ~0xF0;		// Initialize columns LOW
}

//
// Returns ASCII code for key pressed, equal zero if no key pressed.
// Input: none
// Output: pressed key
u8 Key_Scan (void) {
	u8 column, key;
	int i = 0, j;
	key = 0; // default values
	/* scan rows */
	while((ScanTab[i].direction) != 0) {
		DDRC = ScanTab[i].direction; // one row output
		column = PINC;		 // read columns (3 columns in a row)
		/* scan columns */
		for(j = 0; j <= 2; j++) {	
			if((column & 0x01) == 0)	 {	// if key pressed
				key = ScanTab[i].keycode[j];
			}
			column >>= 1; // shift into position
		}
		i++;
	}
	return key;
}