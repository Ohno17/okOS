// Kernel
#include "../Header/TextPrint.h"

extern "C" void _start() {

	SetCursorPosition(PositionFromCoords(0, 0));
	PrintString("Hello World\n\rThis is a New Line!\n\r");
	return;
}