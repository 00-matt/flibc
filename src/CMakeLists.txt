add_library(flibc
  ctype/isblank.c
  ctype/isdigit.c
  ctype/isspace.c
  stdio/sprintf.c
  stdlib/itoa.c
  string/memcmp.c
  string/memcpy.c
  string/memmove.c
  string/memset.c
  string/strlen.c
  string/strnlen.c)
target_include_directories(flibc PUBLIC ../include)
set_target_properties(flibc PROPERTIES
  COMPILE_FLAGS "-ffreestanding -nostdlib"
  C_STANDARD 99
  C_STANDARD_REQUIRED ON
  C_EXTENSIONS OFF)

add_library(flibc::flibc ALIAS flibc)
