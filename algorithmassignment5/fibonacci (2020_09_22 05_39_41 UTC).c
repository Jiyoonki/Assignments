#include <stdio.h>

int fibonacci(int n);

int main(void)
{
    int m;
    printf("Getting Fibonacci number\n");
    printf("input integer m = ");
    scanf_s("%d", &m);
    if (m < 0) return 1;
    for (int i = 0; i <= m; i++) {
        printf("fib(%d) = %d\n", i, fibonacci(i));
    }
    return 0;
}

int fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    int pp = 0;
    int p = 1;
    int result = 0;

    for (int i = 2; i <= n; i++) {
        result = p + pp;
        pp = p;
        p = result;
    }
    return result;
}