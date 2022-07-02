// Contains functions for printing strings and setting the cursor position.
#include "Conversion.h"
#include "TypeDefs.h"
#include "IO.h"
#pragma once
#define VGA_MEMORY (uint_8*)0xb8000
#define VGA_WIDTH 80

uint_16 CursorPosition; 

// Position is a index for 0 to the end of video memory
void ksetcursorpos(uint_16 position) {
	
	outb(0x3D4, 0x0F);	
	outb(0x3D5, (uint_8)(position & 0XFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, ((uint_8)(position >> 8) & 0xFF));
	CursorPosition = position;
	
	if(CursorPosition > 2000) CursorPosition = 2000;

	if(CursorPosition < 0) CursorPosition = 0;
}

uint_16 kpostocoords(uint_8 x, uint_8 y) {

	return y * VGA_WIDTH + x;	
}

/* Print */
void kprintstr(const char* str) {
	uint_8* charPtr = (uint_8*)str;
	uint_16 index = CursorPosition;
	while(*charPtr != 0){
		
		switch(*charPtr){
			case 10:
				index += VGA_WIDTH;
			  break;
			case 13:
				index -= index % VGA_WIDTH;
			  break;
		  default:

			  *(VGA_MEMORY + index * 2 ) = *charPtr;
			  index++;
        break;
		}

		charPtr++;	
	}
	ksetcursorpos(index);
}