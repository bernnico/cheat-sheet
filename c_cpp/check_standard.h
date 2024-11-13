// C++
#if __cplusplus == 199711L
    #warning "This program is compiled with C++98 or C++03"
#elif __cplusplus == 201103L
    #warning "This program is compiled with C++11"
#elif __cplusplus == 201402L
    #warning "This program is compiled with C++14"
#elif __cplusplus == 201703L
    #warning "This program is compiled with C++17"
#elif __cplusplus == 202002L
    #warning "This program is compiled with C++20"
#elif __cplusplus > 202002L
    #warning "This program is compiled with C++23 or newer"
#else
    #ifdef __cplusplus
        #warning "Unknown C++ standard"
    #endif
#endif

// C
#if defined(__STDC_VERSION__)
    #if __STDC_VERSION__ == 199409L
        #warning "This program is compiled with C94"
    #elif __STDC_VERSION__ == 199901L
        #warning "This program is compiled with C99"
    #elif __STDC_VERSION__ == 201112L
        #warning "This program is compiled with C11"
    #elif __STDC_VERSION__ == 201710L
        #warning "This program is compiled with C17"
    #elif __STDC_VERSION__ > 201710L
        #warning "This program is compiled with C2x or newer"
    #else
        #warning "Unknown C standard"
    #endif
#else
    #ifndef __cplusplus
        #warning "This program is compiled with C90 or pre-standard C"
    #endif
#endif
