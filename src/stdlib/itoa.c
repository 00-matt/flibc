#include <stdlib.h>

int itoa(int value, char *buf, unsigned int radix, int sign, unsigned int pad) {
  int neg = 0;
  char *pbuf = buf;
  unsigned int i;
  unsigned int len;

  if (radix > 16) {
    *buf = '\0';
    return 0;
  }

  if (sign && value < 0) {
    neg = 1;
    value = -value;
  }

  do {
    int digit = value % radix;
    *(pbuf++) = (digit < 10 ? '0' + digit : 'A' + digit - 10);
    value /= radix;
  } while (value > 0);

  for (i = pbuf - buf; i < pad; i++) {
    *(pbuf++) = 0;
  }

  if (neg) {
    *(pbuf++) = '-';
  }

  *pbuf = '\0';

  len = pbuf - buf;

  for (i = 0; i < len / 2; i++) {
    char tmp = buf[i];
    buf[i] = buf[len - i - 1];
    buf[len - i - 1] = tmp;
  }

  return len;
}
