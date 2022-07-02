#pragma once
#include "TypeDefs.h"

// Supports any base integers.
// counts how many digits there are by dividing

uint_32 kdigitcount(int num, int base) {
  uint_32 count = 0;
  if (num == 0)
    return 1;
  while (num > 0) {
    count++;
    num = num/base;
  }
  return count;
}

// Converts int to char*
// in any base.


char* itoa(int val, int base){

  static char buf[32] = {0};

  int i = 30;

  for (; val && i ; --i, val /= base) {
    buf[i] = "0123456789ABCDEF"[val % base];
  }
  return &buf[i+1];

}
    
uint_32 kstrlen(const char* str) {
  uint_32 length = 0;
  while (str[length])
    length++;
  return length;
}

const char* kitochar(int value) {
  const char* alphabet = "A\0B\0C\0D\0E\0F\0G\0H\0I\0J\0K\0L\0M\0N\0O\0P\0Q\0R\0S\0T\0U\0V\0W\0X\0Y\0Z\0[\0/\0]\0^\0_\0`\0a\0b\0c\0d\0e\0f\0g\0h\0i\0j\0k\0l\0m\0n\0o\0p\0q\0r\0s\0t\0u\0v\0w\0x\0y\0z\0";
  int index = value - 41;
  if (value < 0 | value > 122) {
    return &alphabet[1];
  }
  return &alphabet[index];
}