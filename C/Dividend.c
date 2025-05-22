#include <stdio.h>

int divide_p(int dividend, int divisor, int *quotient, int *rem)
{
    if (divisor == 0)
    {
        return -1;
    }
    *quotient = dividend / divisor;
    *rem = dividend % divisor;
    return 0;
}

int main()
{
    int i, j, q, r;
    printf("enter dividend\n");
    scanf("%d", &i);
    printf("enter divisor\n");
    scanf("%d", &j);
    if (divide_p(i, j, &q, &r) == -1)
        printf("0으로 나눌 수 없습니다.\n");
    else
        printf("%d / %d : 몫은 %d이고 나머지는 %d입니다.\n", i, j, q, r);
}