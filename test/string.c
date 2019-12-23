#include <flibc-test.h>

extern size_t flibc_strlen(const char *);
extern size_t flibc_strnlen(const char *, size_t);

static void string_strlen_test(void) {
  TEST_ASSERT_EQ(0, flibc_strlen(""));
  TEST_ASSERT_EQ(5, flibc_strlen("hello"));
  TEST_ASSERT_EQ(11, flibc_strlen("flibc sucks"));
  TEST_ASSERT_EQ(12, flibc_strlen("flibc\r\nsucks"));
}

static void string_strnlen_test(void) {
  TEST_ASSERT_EQ(0, flibc_strnlen("", 0));
  TEST_ASSERT_EQ(0, flibc_strnlen("", 1));
  TEST_ASSERT_EQ(5, flibc_strnlen("hello", 5));
  TEST_ASSERT_EQ(4, flibc_strnlen("hello", 4));
}

void string_test(void) {
  string_strlen_test();
  string_strnlen_test();
}
