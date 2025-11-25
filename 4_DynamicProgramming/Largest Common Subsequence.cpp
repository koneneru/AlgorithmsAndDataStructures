#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

int LargestCommonSubsequence()
{
    int n;
    scanf_s("%d", &n);
    int* a = (int*)malloc((n + 1) * sizeof(int));
    if (a == NULL) {
        puts("memory allocation failed");
        return 1;
    }
    for (int i = 1; i <= n; i++) scanf_s("%d", &a[i]);

    int m;
    scanf_s("%d", &m);
    int* b = (int*)malloc((m + 1) * sizeof(int));
    if (b == NULL) {
        puts("memory allocation failed");
        free(a);
        return 1;
    }
    for (int i = 1; i <= m; i++) scanf_s("%d", &b[i]);

    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    if (dp == NULL) {
        puts("memory allocation failed");
        free(a);
        free(b);
        return 1;
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)calloc(m + 1, sizeof(int));
        if (dp[i] == NULL) {
            puts("memory allocation failed");
            free(a);
            free(b);
            for (int j = 0; j < i; j++) free(dp[j]);
            return 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("%d", dp[n][m]);

    return 0;
}
