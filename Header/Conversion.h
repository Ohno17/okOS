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
    buf[i] = "0123456789abcdef"[val % base];
  }
  return &buf[i+1];

}
    
uint_32 kstrlen(const char* str) {
  uint_32 length = 0;
  while (str[length])
    length++;
  return length;
}