#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include <stdio.h>


typedef int                                INT32;
typedef char                             CHAR;
typedef unsigned char               UCHAR;
typedef unsigned char               UINT8;
typedef unsigned short             UINT16;
typedef unsigned long               UINT32;
typedef void                             VOID;
typedef VOID*                          HANDLE;
typedef double  			     DOUBLE;
typedef UINT8                          BOOL;



#ifndef NULL
    #define NULL                0
#endif  // NULL

#ifndef TRUE
    #define TRUE                (0 == 0)
#endif  // TRUE

#ifndef FALSE
    #define FALSE               (0 != 0)
#endif  // FALSE




#endif

