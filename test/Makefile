CFLAGS = \
	-MD \
	-Os \
	-Wall \
	-Wextra \
	-Wpedantic \
	-g \
	-std=c99
CPPFLAGS = -I.

OBJS = \
	ctype.o \
	main.o \
	stdio.o \
	stdlib.o \
	string.o
DEPS = $(OBJS:.o=.d)

.PHONY: all
all: flibc-test

libflibc-prefixed.a: ../libflibc.a
	objcopy ../libflibc.a --prefix-symbols=flibc_ libflibc-prefixed.a

flibc-test: $(OBJS) libflibc-prefixed.a
	$(CC) -o flibc-test $(CFLAGS) $(LDFLAGS) $(OBJS) libflibc-prefixed.a \
		$(LDLIBS)

.PHONY: test
test: flibc-test
	./flibc-test

.PHONY: clean
clean:
	$(RM) flibc-test libflibc-prefixed.a $(OBJS) $(DEPS)

-include $(DEPS)
