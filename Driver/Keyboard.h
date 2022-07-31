#include "TextPrint.h"
#include "Conversion.h"
#include "KBDScanset.h"
#include "TypeDefs.h"

void ktype(uint_16 val) {
  uint_8 capsbool = 0;
  char charval;
  if (val == 0x2A) {
    capsbool = 1;
  }
  switch(val) {
    default:
      switch(capsbool) {
        case 0:
          charval = us_keyboard(val);
          break;
        case 1: 
          charval = us_caps(val);
          break;
        default:
          charval = '?';
          break;
      }
      break;
  }
  switch(charval) {
    case 7: break;
    case 8:
      ksetcursorpos(CursorPosition-1);
      *(VGA_MEMORY + CursorPosition * 2) = NULL;
      // Backspace
      break;
    case 9:
      kprintstr("  ");
      // Tab
      break;
    case 10:
    	CursorPosition += VGA_WIDTH;
      CursorPosition -= CursorPosition % VGA_WIDTH;
      // Enter
      ksetcursorpos(CursorPosition);
      break;
    default:
      *(VGA_MEMORY + CursorPosition * 2) = charval;
      // Any character
	    ksetcursorpos(CursorPosition + 1);
      break;
  }
}