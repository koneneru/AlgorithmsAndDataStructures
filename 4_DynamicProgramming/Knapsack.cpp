#include <stdio.h>
#include <stdlib.h>

int Knapsack()
{
    int s, n;
    scanf_s("%d %d", &s, &n);

    int* w = (int*)malloc(n * sizeof(int));
    int* dp = (int*)calloc(s + 1, sizeof(int));
    if (w == NULL || dp == NULL) {
        puts("memory allocation failed");
        return 1;
    }
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        scanf_s("%d", &w[i]);
    }

    for (int i = 0; i < n; i++) {
        if (s < w[i]) continue;

        for (int j = s; w[i] <= j; j--) {
            if (!dp[j] && dp[j - w[i]]) dp[j] = 1;
        }
    }

    int ans;
    for (int i = s; 0 <= i; i--) {
        if (dp[i]) {
            ans = i;
            break;
        }
    }

    printf("%d", ans);

    free(dp);
    free(w);

    return 0;
}
