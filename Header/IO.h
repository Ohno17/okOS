#pragma once

void outb(unsigned short port, unsigned char val){

	asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
		
}
// A little bit of inline C and Assembly
unsigned char inb(unsigned short port, unsigned char val){

	unsigned char returnVal;

	asm volatile ("inb %1, %0"
	: "=a"(returnVal)
	: "Nd"(port));
	
	return returnVal;

}