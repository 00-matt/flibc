#include <flibc-test.h>

extern size_t flibc_strlen(const char *);

static void string_strlen_test(void) {
  TEST_ASSERT_EQ(0, flibc_strlen(""));
  TEST_ASSERT_EQ(5, flibc_strlen("hello"));
  TEST_ASSERT_EQ(11, flibc_strlen("flibc sucks"));
  TEST_ASSERT_EQ(12, flibc_strlen("flibc\r\nsucks"));
}

void string_test(void) { string_strlen_test(); }
