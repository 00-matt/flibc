#include <stdio.h>

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int sprintf(char *str, const char *fmt, ...) {
  char buf[12];
  int n = 0;
  va_list params;
  va_start(params, fmt);

  while (*fmt) {
    if (fmt[0] != '%' || fmt[1] == '%') {
      if (fmt[0] == '%') {
        fmt++;
      }
      size_t i = 1;
      while (fmt[i] && fmt[i] != '%') {
        i++;
      }
      memcpy(str, fmt, i);
      str += i;
      fmt += i;
      n += i;
      continue;
    }

    const char *start = fmt++;

    if (*fmt == 'c') {
      fmt++;
      char c = (char)va_arg(params, int);
      *str = c;
      str++;
      n++;
    } else if (*fmt == 's') {
      fmt++;
      char *s = (char *)va_arg(params, char *);
      size_t len = strlen(s);
      memcpy(str, s, len);
      str += len;
      n += len;
    } else if (*fmt == 'd' || *fmt == 'x') {
      int base = *fmt == 'd' ? 10 : 16;
      fmt++;
      int val = va_arg(params, int);
      size_t len = itoa(val, buf, base, 1, 0);
      memcpy(str, buf, len);
      str += len;
      n += len;
    } else if (*fmt == 'p') {
      fmt++;
      size_t val = va_arg(params, size_t);
      size_t len = itoa(val, buf, 16, 0, 0);
      memcpy(str, buf, len);
      str += len;
      n += len;
    } else {
      fmt = start;
      size_t len = strlen(fmt);
      memcpy(str, fmt, len);
      str += len;
      n += len;
      fmt += len;
    }
  }

  *str = '\0';

  va_end(params);
  return n;
}
