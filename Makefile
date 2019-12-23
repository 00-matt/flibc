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

OBJS = \
	src/string/memcmp.o \
	src/string/memcpy.o \
	src/string/memmove.o \
	src/string/memset.o \
	src/string/strlen.o
DEPS = $(OBJS:.o=.d)

.PHONY: all
all: flibc.a

flibc.a: $(OBJS)
	$(AR) rcs flibc.a $(OBJS)

.PHONY: clean
clean:
	$(RM) flibc.a $(OBJS) $(DEPS)

-include $(DEPS)
