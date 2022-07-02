// Kernel
#include "../Header/TextPrint.h"

extern "C" void _start() {

	ksetcursorpos(kcoordstoindex(1, 1));
	kprintstr("Hello, World!");
  ksetcursorpos(kcoordstoindex(1, 2));
  kprintstr("This is a New Line!");
  ksetcursorpos(kcoordstoindex(1, 3));
  kprintstr("Wow a integer! Here it is: ");
  kprintstr(itoa(10, 10));
  ksetcursorpos(kcoordstoindex(1, 4));
  kprintstr(kitochar(412873872));
	return;
}