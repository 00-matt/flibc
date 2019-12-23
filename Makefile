CFLAGS = \
	-MD \
	-Os \
	-Wall \
	-Wextra \
	-Wpedantic \
	-ffreestanding \
	-g \
	-nostdlib \
	-std=c99
CPPFLAGS = -Iinclude

OBJS = \
	src/string/memcmp.o \
	src/string/memcpy.o \
	src/string/memmove.o \
	src/string/memset.o \
	src/string/strlen.o \
	src/string/strnlen.o
DEPS = $(OBJS:.o=.d)

.PHONY: all
all: flibc.a

flibc.a: $(OBJS)
	$(AR) rcs flibc.a $(OBJS)

.PHONY: test
test: flibc.a
	$(MAKE) -C test test

.PHONY: clean
clean:
	$(RM) flibc.a $(OBJS) $(DEPS)
	$(MAKE) -C test clean

-include $(DEPS)
