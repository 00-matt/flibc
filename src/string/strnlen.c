#include <string.h>

size_t strnlen(const char *s, size_t max) {
  size_t i = 0;
  while (i < max && s[i]) {
    i++;
  }
  return i;
}
