// Kernel
#include "../Header/TextPrint.h"

extern "C" void _start() {

	ksetcursorpos(kpostocoords(1, 1));
	kprintstr("Hello, World!");
  ksetcursorpos(kpostocoords(1, 2));
  kprintstr("This is a New Line!");
  ksetcursorpos(kpostocoords(1, 3));
  kprintstr("Wow a integer! Here it is: ");
  kprintstr(itoa(10, 10));
  ksetcursorpos(kpostocoords(1, 4));
  char str[5];
  kprintstr(kitostr(1234, &str[0]));
	return;
}