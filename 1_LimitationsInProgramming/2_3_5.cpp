#include <stdio.h>
#include "1_LimitationsInProgramming.h"

int min(int a, int b) {
    return a < b ? a : b;
}

int minOf3(int a, int b, int c) {
    return min(min(a, b), min(b, c));
}

int a[1651] = { 1 };

int Problem2_3_5()
{
    int n;
    scanf_s("%d", &n);

    int i2, i3, i5;
    i2 = i3 = i5 = 0;
    for (int i = 1; i <= n; i++) {
        int next = minOf3(a[i2] << 1, 3 * a[i3], 5 * a[i5]);
        a[i] = next;

        if (next == a[i2] << 1) i2++;
        if (next == 3 * a[i3]) i3++;
        if (next == 5 * a[i5]) i5++;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}