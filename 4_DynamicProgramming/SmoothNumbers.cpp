#include <stdio.h>

int SmoothNumbers()
{
    int n;
    scanf_s("%d", &n);

    long long dp[36][10] = { 0 };
    for (int i = 1; i < 10; i++) dp[1][i] = 1;

    for (int i = 2; i <= n;i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] += dp[i - 1][j];
            if (0 <= j - 1) dp[i][j] += dp[i - 1][j - 1];
            if (j + 1 <= 9) dp[i][j] += dp[i - 1][j + 1];
        }
    }

    long long sum = 0;
    for (int i = 0;i < 10; i++) sum += dp[n][i];

    printf("%lld", sum);

    return 0;
}
