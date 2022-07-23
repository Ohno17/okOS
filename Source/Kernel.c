// Kernel
#include "IDT.c"

void _start() {
  ksetcursorpos(0);
  kprintchar('s');
  write_serial('a'); // For debug
	return;
}