#ifndef __BKDEBUG__
#define __BKDEBUG__
#include <stdio.h>

#ifdef _DEBUG
#define VAR(x, format) \
    printf("[D][%s][%d]name=%s, value=%"#format"\n", __FILE__, __LINE__, #x, x); \
    syslog(LOG_DEBUG, "[D][%s][%d]name=%s, value=%"#format"\n", __FILE__, __LINE__, #x, x)
#else
#define VAR(x, format)
#endif

#ifdef _DEBUG
#define BKDEBUG(format, args...) \
    fprintf(stderr, "[D][%s %s][%s][%s][%d]"format"\n", __DATE__,__TIME__,__FILE__,__func__,__LINE__,##args); \
    syslog(LOG_DEBUG, "[D][%s %s][%s][%s][%d]"format"\n", __DATE__,__TIME__,__FILE__,__func__,__LINE__,##args)
#else
#define BKDEBUG(format, args...)
#endif

#ifdef _DEBUG
#define DEBUG_BIT128(in) \
    fprint_hex(stderr,in, 16)
#else
#define DEBUG_BIT128(in)
#endif

#ifdef _DEBUG
#define DEBUG_BIT192(in) \
    fprint_hex(stderr,in, 24)
#else
#define DEBUG_BIT192(in)
#endif

#ifdef _DEBUG
#define DEBUG_BIT256(in) \
    fprint_hex(stderr,in, 32)
#else
#define DEBUG_BIT256(in)
#endif

#define BKERR(format, args...) \
    fprintf(stderr, "[E][%s %s][%s][%s][%d]"format"\n", __DATE__,__TIME__,__FILE__,__func__,__LINE__,##args); \
    syslog(LOG_DEBUG, "[E][%s %s][%s][%s][%d]"format"\n", __DATE__,__TIME__,__FILE__,__func__,__LINE__,##args)

#define BKDSP(format, args...) \
    fprintf(stdout, "[I][%s %s][%s][%s][%d]"format"\n", __DATE__,__TIME__,__FILE__,__func__,__LINE__,##args); \
    syslog(LOG_DEBUG, "[I][%s %s][%s][%s][%d]"format"\n", __DATE__,__TIME__,__FILE__,__func__,__LINE__,##args)

#define DSP_BIT128(in) \
    fprint_hex(stdout,in, 16)
#define DSP_BIT192(in) \
    fprint_hex(stdout,in, 24)
#define DSP_BIT256(in) \
    fprint_hex(stdout,in, 32)

#endif

int fprint_hex(FILE *stdiostream,unsigned char in[], int len);
