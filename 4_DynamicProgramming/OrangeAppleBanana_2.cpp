#include <stdio.h>
#include "4_DynamicProgramming.h"

int OrangeAppleBanana_2()
{
    int o, a, b;
    scanf_s("%d\n%d\n%d", &o, &a, &b);

    long long dp[13][13][13] = { 0 };
    dp[0][0][0] = 1;

    for (int i = 0; i <= o; i++) {
        for (int j = 0; j <= a; j++) {
            for (int k = 0; k <= b;k++) {
                if (i == 0 && j == 0 && k == 0) continue;

                if (0 < i) dp[i][j][k] += dp[i - 1][j][k];
                if (0 < j) dp[i][j][k] += dp[i][j - 1][k];
                if (0 < k) dp[i][j][k] += dp[i][j][k - 1];
            }
        }
    }

    printf("%lld", dp[o][a][b]);

    return 0;
}
