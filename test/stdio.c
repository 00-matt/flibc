#include <string.h>

#include <flibc-test.h>

extern int flibc_sprintf(char *, const char *, ...);

static void stdio_sprintf_test(void) {
  char buf[64];

  TEST_ASSERT_EQ(1, flibc_sprintf(buf, "%%"));
  TEST_ASSERT(strncmp(buf, "%", sizeof(buf)) == 0);

  TEST_ASSERT_EQ(5, flibc_sprintf(buf, "hello"));
  TEST_ASSERT(strncmp(buf, "hello", sizeof(buf)) == 0);

  TEST_ASSERT_EQ(1, flibc_sprintf(buf, "%c", 'a'));
  TEST_ASSERT(strncmp(buf, "a", sizeof(buf)) == 0);

  TEST_ASSERT_EQ(2, flibc_sprintf(buf, "%c%c", 'a', 'b'));
  TEST_ASSERT(strncmp(buf, "ab", sizeof(buf)) == 0);

  TEST_ASSERT_EQ(3, flibc_sprintf(buf, "%c %c", 'a', 'b'));
  TEST_ASSERT(strncmp(buf, "a b", sizeof(buf)) == 0);

  TEST_ASSERT_EQ(1, flibc_sprintf(buf, "%d", 0));
  TEST_ASSERT(strncmp(buf, "0", sizeof(buf)) == 0);

  TEST_ASSERT_EQ(2, flibc_sprintf(buf, "%x", 255));
  TEST_ASSERT(strncmp(buf, "FF", sizeof(buf)) == 0);

  TEST_ASSERT_EQ(10, flibc_sprintf(buf, "%d", 2147483647));
  TEST_ASSERT(strncmp(buf, "2147483647", sizeof(buf)) == 0);

  TEST_ASSERT_EQ(11, flibc_sprintf(buf, "%d", -2147483648));
  TEST_ASSERT(strncmp(buf, "-2147483648", sizeof(buf)) == 0);
}

void stdio_test(void) { stdio_sprintf_test(); }
