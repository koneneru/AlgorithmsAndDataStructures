#include <stdio.h>
#include "4_DynamicProgramming.h"

int Problem2_3Stairs()
{
    int n;
    scanf_s("%d", &n);

    long long s1 = 0ll;
    long long  s2 = 1ll;
    long long  s3 = 1ll;

    for (int i = 4; i <= n; i++) {
        long long  s = s1 + s2;
        s1 = s2;
        s2 = s3;
        s3 = s;
    }

    printf("%lld", n != 1 ? s3 : 0);

    return 0;
}
