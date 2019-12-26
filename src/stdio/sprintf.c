#include <stdio.h>

#include <stdarg.h>
#include <stddef.h>
#include <string.h>

int sprintf(char *str, const char *fmt, ...) {
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
    }
  }

  *str = '\0';

  va_end(params);
  return n;
}
