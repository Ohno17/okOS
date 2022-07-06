#pragma once
#include "TypeDefs.h"

#define PIC1 0x20
#define PIC2 0xA0

#define ICW1 0x11
#define ICW4 0x01

void outb(unsigned short port, unsigned char val){

	asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
		
}

unsigned char inb(unsigned short port){

	unsigned char returnVal;

	asm volatile ("inb %1, %0"
	: "=a"(returnVal)
	: "Nd"(port));
	
	return returnVal;

}

void init_pics(int pic1, int pic2) {
   /* send ICW1 */
   outb(PIC1, ICW1);
   outb(PIC2, ICW1);

   /* send ICW2 */
   outb(PIC1 + 1, pic1);   
   outb(PIC2 + 1, pic2);   

   /* send ICW3 */
   outb(PIC1 + 1, 4);   
   outb(PIC2 + 1, 2);

   /* send ICW4 */
   outb(PIC1 + 1, ICW4);
   outb(PIC2 + 1, ICW4);

   /* disable all IRQs */
   outb(PIC1 + 1, 0xFF);
}

static inline void io_wait(void) {
  outb(0x80, 0);
}