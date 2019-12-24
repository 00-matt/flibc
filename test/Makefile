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
	string.o
DEPS = $(OBJS:.o=.d)

.PHONY: all
all: flibc-test

flibc-prefixed.a: ../flibc.a
	objcopy ../flibc.a --prefix-symbols=flibc_ flibc-prefixed.a

flibc-test: $(OBJS) flibc-prefixed.a
	$(CC) -o flibc-test $(CFLAGS) $(LDFLAGS) $(OBJS) flibc-prefixed.a \
		$(LDLIBS)

.PHONY: test
test: flibc-test
	./flibc-test

.PHONY: clean
clean:
	$(RM) flibc-test flibc-prefixed.a $(OBJS) $(DEPS)

-include $(DEPS)
