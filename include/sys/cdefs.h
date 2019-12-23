#ifndef _SYS_CDEFS_H
#define _SYS_CDEFS_H 1

#define __flibc 1

#ifdef __cplusplus
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS }
#else // __cplusplus
#define __BEGIN_DECLS
#define __END_DECLS
#endif // __cplusplus

#endif
