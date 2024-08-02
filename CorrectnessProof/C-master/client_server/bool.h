
#ifndef __BOOL_H__
#define __BOOL_H__


#ifdef BOOL
#undef BOOL
#endif

#ifdef TRUE
#undef TRUE
#endif

#ifdef FALSE
#undef FALSE
#endif


#ifndef  _MSC_VER
typedef enum
{
    FALSE = 0,
    TRUE = 1
} BOOL;

#else



typedef int BOOL;
#define FALSE 0
#define TRUE 1

#endif

#define BOOLtobool(w)     ((w != FALSE) ? true : false)


#define booltoBOOL(w)     ((w == true) ? TRUE : FALSE)

#endif 

