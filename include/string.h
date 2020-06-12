#ifndef _STRING_H
#define _STRING_H 1

#include <stddef.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

int memcmp(const void *, const void *, size_t);

void *memcpy(void *, const void *, size_t);

void *memmove(void *, const void *, size_t);

void *memset(void *, int, size_t);

size_t strlen(const char *);

size_t strnlen(const char *, size_t);

__END_DECLS

#endif
