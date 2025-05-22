#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int (*fp)(int, int); // khai báo con trỏ hàm
    int res;
    fp = sum; // con trỏ hàm trỏ đến hàm sum
    res = fp(10, 20);
    printf("result : %d", res);
}