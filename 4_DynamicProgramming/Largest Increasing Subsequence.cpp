#include <stdio.h>
#include <stdlib.h>

int LargestIncreasingSubsequence()
{
    int n;
    scanf_s("%d", &n);

    int* x = (int*)malloc(n * sizeof(int));
    int* dp = (int*)malloc(n * sizeof(int));
    if (x == NULL || dp == NULL) {
        puts("memory allocation failed");
        if (x) free(x);
        if (dp) free(dp);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf_s("%d", &x[i]);
    }

    int len = 0;

    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int m = (l + r) >> 1;
            if (dp[m] < x[i]) l = m + 1;
            else r = m;
        }

        dp[l] = x[i];
        if (l == len) len++;
    }

    printf("%d", len);

    free(dp);
    free(x);

    return 0;
}
