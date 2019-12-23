#include <stddef.h>
#include <stdio.h>

#include <flibc-test.h>

extern void string_test(void);

int assertions_fail = 0;
int assertions_total = 0;

int main(int argc, char **argv) {
  string_test();
  if (assertions_fail != 0) {
    printf("%d assertions failed\n", assertions_fail);
    return 1;
  }
  return 0;
}
