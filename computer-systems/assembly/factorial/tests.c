#include <assert.h>
#include <stdio.h>

extern int fact(int n);

int main(void) {
  assert(fact(0) == 1);
  assert(fact(1) == 1);
  assert(fact(2) == 2);
  assert(fact(3) == 6);
  assert(fact(4) == 24);
  assert(fact(5) == 120);
  printf("OK\n");
}
