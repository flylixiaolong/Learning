#ifndef __DEFINE_HELLO_H
#define __DEFINE_HELLO_H

#ifdef _WIN32
    #if LIBHELLO_BUILD
        #define LIBHELLO_API __declspec(dllexport)
    #else
        #define LIBHELLO_API __declspec(dllimport)
    #endif
#else
    #define LIBHELLO_API
#endif

LIBHELLO_API void hello(const char* name);

#endif
