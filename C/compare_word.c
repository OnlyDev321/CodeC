#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_word(const void *p, const void *q)
{
    return strcmp(*(char **)p, *(char **)q);
}

int main()
{
    char *arr[] = {"banana", "apple", "cherry", "mango", "pear"};
    char n = sizeof(arr) / sizeof(arr[0]);

    // sap xep mang bang qsort
    qsort(arr, n, sizeof(char *), compare_word);

    for (int i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
    }
}