#include <stdio.h>
#include "../common.h"
#include "4_DynamicProgramming.h"

int EditorialDistance_1()
{
    char a[2001] = { 0 };
    char b[2001] = { 0 };
    scanf_s("%s", &a, 2000);
    scanf_s("%s", &b, 2000);

    int n = 0, m = 0;
    while (a[++n]);
    while (b[++m]);

    int dp[2][2001] = { 0 };
    int* prev = dp[0];
    int* cur = dp[1];

    for (int i = 0; i <= m; i++) prev[i] = i;

    for (int i = 1; i <= n; i++) {
        cur[0] = i;

        for (int j = 1; j <= m;j++) {
            int c = a[i - 1] == b[j - 1] ? 0 : 1;

            cur[j] = minOf3(prev[j] + 1, cur[j - 1] + 1, prev[j - 1] + c);
        }

        int* temp = prev;
        prev = cur;
        cur = temp;
    }

    printf("%d", prev[m]);

    return 0;
}
