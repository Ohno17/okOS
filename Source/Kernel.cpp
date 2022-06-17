// C++ Kernel entrypoint (really it is C)
#include "TextPrint.cpp"

extern "C" void _start(){

	SetCursorPos(PositionFromCoords(1,0));
	PrintString("Hello, World!\n\rThis is a new line!\n\r");
  PrintString(HexToString(0x1234abcd));
	return;	
}