#include <stdio.h>
#include <stdlib.h>

int compare_char(const void *p, const void *q)
{
    return (*(char *)p - *(char *)q);
}

int main()
{
    char arr[] = {'a', 'e', 'b', 'd', 'c'};
    char n = sizeof(arr) / sizeof(arr[0]);

    // sap xep mang bang qsort
    qsort(arr, n, sizeof(char), compare_char);

    for (int i = 0; i < n; i++)
    {
        printf("%c ", arr[i]);
    }
}
