#include <string.h>

#include <flibc-test.h>

extern int flibc_itoa(int value, char *buf, unsigned int radix, int sign,
                      unsigned int pad);

static void stdlib_itoa_test(void) {
  char buf[12];

  TEST_ASSERT_EQ(1, flibc_itoa(0, buf, 10, 1, 0));
  TEST_ASSERT(strncmp(buf, "0", sizeof(buf)) == 0);

  TEST_ASSERT_EQ(3, flibc_itoa(255, buf, 10, 1, 0));
  TEST_ASSERT(strncmp(buf, "255", sizeof(buf)) == 0);

  TEST_ASSERT_EQ(2, flibc_itoa(255, buf, 16, 1, 0));
  TEST_ASSERT(strncmp(buf, "FF", sizeof(buf)) == 0);
}

void stdlib_test(void) { stdlib_itoa_test(); }
