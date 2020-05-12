# flibc

Freestanding libc implementation.
Useful for operating system kernels, bootloaders, small statically
linked applications, or as a starting point for your own libc.

## Implemented Methods

### `ctype.h`

* `isblank`
* `isdigit`
* `isspace`

### `stdlib.h`

* `itoa`

### `string.h`

* `memcmp`
* `memcpy`
* `memmove`
* `memset`
* `strlen`
* `strnlen`

## Project Non-Goals

* Locales
* Wide chars

## License

Released under the terms of the MIT license.
See LICENSE file in project root for more details.
