#pragma once

char us_keyboard(uint_16 index) {
  return("\0\a1234567890-=\b\tqwertyuiop[]\n\0asdfghjkl;\'`\0\\zxcvbnm,./\0\0 "[index]);
}

char us_caps(uint_16 index) {
  return ("\0\a!@#$%^&*()_+\b\tQWERTYUIOP{}\n\0ASDFGHJKL:\"~\0\\ZXCVBNM<>?\0\0 "[index]);
}