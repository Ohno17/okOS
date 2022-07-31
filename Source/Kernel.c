// Kernel
#include "/home/runner/okOS/Driver/Serial.h"
#include "/home/runner/okOS/Header/TextPrint.h"

void _start() {
  ksetcursorpos(0);
  kprintstr("Welcome to this blue screen. Forever.\n\rHello, world!");
  serialoutstr("\n\rHello outside world!");
  // For debug, the serial port redirects to our console.
  // Usually, the serial port goes to a physical port on a computer.
	return;
}