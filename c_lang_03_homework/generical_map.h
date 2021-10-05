#pragma once

#define MapArray(src, dest, func, num) \
do {				       \
   unsigned i;                         \
   for (i = 0; i<num; i++)             \
      dest[i] = func(src[i]);          \
} while (0)


int func(int a) { return a + 100; }