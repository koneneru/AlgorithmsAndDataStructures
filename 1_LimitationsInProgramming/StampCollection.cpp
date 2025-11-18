#include <stdio.h>
#include "1_LimitationsInProgramming.h"

int x[100001] = { 0 };

int StampCollection()
{
    int n;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        int p;
        scanf_s("%d", &p);
        if (p <= 100000)
            x[p] = 1;
    }
    int i = 1;
    for (i; i < 100001; i++) {
        if (!x[i]) {
            printf("%d", i);
            break;
        }
    }

    if (i == 100001) puts("100001");

    return 0;
}