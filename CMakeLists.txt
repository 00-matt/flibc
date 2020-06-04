cmake_minimum_required(VERSION 3.7)
project(flibc)

add_library(flibc
    src/ctype/isblank.c
    src/ctype/isdigit.c
    src/ctype/isspace.c
    src/stdio/sprintf.c
    src/stdlib/itoa.c
    src/string/memcmp.c
    src/string/memcpy.c
    src/string/memmove.c
    src/string/memset.c
    src/string/strlen.c
    src/string/strnlen.c)

target_compile_options(flibc PRIVATE -ffreestanding -nostdlib)
target_include_directories(flibc PUBLIC include)
target_link_options(flibc PRIVATE LINKER:-nostdlib)
