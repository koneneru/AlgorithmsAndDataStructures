#include <stdio.h>
#include <stdlib.h>

int ClassicFibonacciNumbers_2()
{
    int n;
    scanf_s("%d", &n);

    long long f1 = 0;
    long long f2 = 1;

    while (n--) {
        long long f = f1 + f2;
        f1 = f2;
        f2 = f;
    }

    printf("%lld", f1);

    return 0;
}

