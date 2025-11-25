#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

int ColoredBowling()
{
    int n;
    scanf_s("%d", &n);

    int* b = (int*)malloc((n + 1) * sizeof(int));
    int* p = (int*)malloc((n + 1) * sizeof(int));
    int* c = (int*)malloc((n + 1) * sizeof(int));
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    if (!b || !p || !c || !dp) {
        puts("memory allocation failed");
        free(b);
        free(p);
        free(c);
        free(dp);
        return 1;
    }

    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)calloc((n + 1), sizeof(int));
        if (dp[i] == NULL) {
            puts("memory allocation failed");
            for (int j = 0; j < i; j++) {
                free(dp[j]);
            }
            free(b);
            free(p);
            free(c);
            free(dp);
            return 1;
        }
    }
    for (int i = 1; i <= n; i++) scanf_s("%d", &b[i]);
    for (int i = 1; i <= n; i++) scanf_s("%d", &p[i]);
    for (int i = 1; i <= n; i++) scanf_s("%d", &c[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);

            if (1 <= j) {
                int gain = b[i] == p[j] ? c[j] : 0;
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + gain);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ans < dp[n][i]) ans = dp[n][i];
    }

    printf("%d", ans);

    free(b);
    free(p);
    free(c);
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return 0;
}
