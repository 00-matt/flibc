#include <flibc-test.h>

extern int flibc_isblank(int);
extern int flibc_isspace(int);

static void ctype_isblank_test(void) {
  TEST_ASSERT(flibc_isblank(' '));
  TEST_ASSERT(flibc_isblank('\t'));
  TEST_ASSERT(!flibc_isblank('\n'));
  TEST_ASSERT(!flibc_isblank('a'));
}

static void ctype_isspace_test(void) {
  TEST_ASSERT(flibc_isspace(' '));
  TEST_ASSERT(flibc_isspace('\r'));
  TEST_ASSERT(flibc_isspace('\n'));
  TEST_ASSERT(flibc_isspace('\f'));
  TEST_ASSERT(flibc_isspace('\t'));
  TEST_ASSERT(flibc_isspace('\v'));
  TEST_ASSERT(!flibc_isspace('a'));
  TEST_ASSERT(!flibc_isspace('\x00'));
  TEST_ASSERT(!flibc_isspace('@'));
}

void ctype_test(void) {
  ctype_isblank_test();
  ctype_isspace_test();
}
