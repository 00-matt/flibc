#ifndef _FLIBC_TEST_H
#define _FLIBC_TEST_H 1

#include <stdio.h>

#define S2(x) #x
#define S(x) S2(x)

#define TEST_ASSERT(test)                                                      \
  do {                                                                         \
    assertions_total++;                                                        \
    if (!(test)) {                                                             \
      assertions_fail++;                                                       \
      fputs(__FILE__ ":" S(__LINE__) " Assertion failed \n", stderr);          \
    }                                                                          \
  } while (0)

#define TEST_ASSERT_EQ(lhs, rhs) TEST_ASSERT(lhs == rhs)

extern int assertions_fail;
extern int assertions_total;

#endif
