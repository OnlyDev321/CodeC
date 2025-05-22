#include <stdio.h>

// Định nghĩa macro MY_MACRO
#define MY_MACRO 1

int main()
{
#ifdef MY_MACRO
    printf("MY_MACRO đã được định nghĩa.\n");
#else
    printf("MY_MACRO chưa được định nghĩa.\n");
#endif

#ifndef YOUR_MACRO
    printf("YOUR_MACRO chưa được định nghĩa.\n");
#else
    printf("YOUR_MACRO đã được định nghĩa.\n");
#endif

    return 0;
}