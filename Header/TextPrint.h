// Contains functions for printing strings and setting the cursor position.
#include "Conversion.h"
#include "TypeDefs.h"
#include "IO.h"
#pragma once
#define VGA_MEMORY (uint_8*)0xb8000
#define VGA_WIDTH 80

uint_16 CursorPosition; 
uint_8 CountScreenClear;

void kclearscreen(uint_64 ClearColor){
	CountScreenClear = 0;
	uint_64 value = 0;
	value += ClearColor << 8;
	value += ClearColor << 24;
	value += ClearColor << 40;
	value += ClearColor << 56;
	for (uint_64* i = (uint_64*)VGA_MEMORY; i < (uint_64*)(VGA_MEMORY + 40000); i++){
		*i = value;	
		CountScreenClear++;
	}
}

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

uint_16 kcoordstoindex(uint_8 x, uint_8 y) {

	return y * VGA_WIDTH + x;	
}

// Print
// The background and foreground colors are left alone.

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
			  *(VGA_MEMORY + index * 2) = *charPtr;
        index++;
        break;
		}

		charPtr++;	
	}
	ksetcursorpos(index);
}

// Print "formmatted" string.
// Print a string with color.

void kprintfstr(const char* str, int color) {
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
			  *(VGA_MEMORY + index * 2) = *charPtr;
        index++;
        *((VGA_MEMORY + index * 2) - 1) = color;
        break;
		}

		charPtr++;	
	}
	ksetcursorpos(index);
}

void kprintfchar(char chr, uint_8 color) {
  switch(chr) {
    case 0: break;
    case 10:
			CursorPosition += VGA_WIDTH;
		  break;
		case 13:
			CursorPosition -= CursorPosition % VGA_WIDTH;
		  break;
    default:
      *(VGA_MEMORY + CursorPosition * 2) = chr;
	    *(VGA_MEMORY + CursorPosition * 2 + 1) = color; 
	    ksetcursorpos(CursorPosition + 1);
      break;
  }
}

void kprintchar(char chr) {
  switch(chr) {
    case 0: break;
    case 10:
			CursorPosition += VGA_WIDTH;
		  break;
		case 13:
			CursorPosition -= CursorPosition % VGA_WIDTH;
		  break;
    default:
      *(VGA_MEMORY + CursorPosition * 2) = chr;
	    ksetcursorpos(CursorPosition + 1);
      break;
  }
}