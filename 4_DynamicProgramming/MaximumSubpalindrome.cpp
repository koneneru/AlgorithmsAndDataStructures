#include <stdio.h>
#include <stdlib.h>
#include "4_DynamicProgramming.h"

int MaxSubpalindrome()
{
    char s[2001] = { 0 };
    scanf_s("%s", &s, 2001);

    int n = 0, best = 1;
    while (s[n]) n++;

    char** dp = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        dp[i] = (char*)calloc(n, sizeof(char));
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            dp[i - 1][i] = 1;
            best = 2;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if (s[l] == s[r] && dp[l + 1][r - 1]) {
                dp[l][r] = 1;
                best = len;
            }
        }
    }

    // DEBUG
    /*for (int i = 0; i < n; i++) {
        printf("%c ", s[i]);
    }
    putchar('\n');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) putchar(' ');
            if (dp[i][j]) printf("%d", dp[i][j]);
            else putchar(' ');
        }
        putchar('\n');
    }*/

    printf("%d", best);

    for (int i = 0; i < n; i++) free(dp[i]);
    free(dp);

    return 0;
}
