#include <stdio.h>

typedef union
{
    int s;
    float f;
} int_or_float;

int main()
{
    int_or_float n1 = {10};
    int_or_float n2 = {.f = 10.5};
    printf("n1 : %d\n", n1.s);
    printf("n2 : %f\n", n2.f);
}