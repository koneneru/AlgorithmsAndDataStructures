#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

int EditorialDistance_2()
{
    int k, n = 0, m = 0, result = 0, dp_len, ans, inf = 0x0FFFFFF0;
    char* a = NULL, * b = NULL;
    int* dp_prev = NULL, * dp_cur = NULL;

    a = (char*)calloc(100001, sizeof(char));
    b = (char*)calloc(100001, sizeof(char));
    if (!a || !b) {
        puts("memory allocation failed");
        result = 1;
        goto cleanup;
    }

    scanf_s("%s", a, 100001);
    scanf_s("%s", b, 100001);
    scanf_s("%d", &k);

    while (a[++n]);
    while (b[++m]);

    if (k < abs(n - m)) {
        fputs("-1", stdout);
        goto cleanup;
    }

    dp_len = (k << 1) + 1;
    dp_prev = (int*)calloc(dp_len, sizeof(int));
    dp_cur = (int*)calloc(dp_len, sizeof(int));
    if (!dp_prev || !dp_cur) {
        puts("memory allocation failed");
        result = 1;
        goto cleanup;
    }

    for (int i = 0; i < dp_len; i++) {
        int idx = i - k;
        if (0 <= idx && idx <= n) dp_prev[i] = idx;
        else dp_prev[i] = inf;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < dp_len; j++) {
            int col = i + j - k;
            if (col < 0 || n < col) {
                dp_cur[j] = inf;
                continue;
            }

            int cost = (a[col - 1] == b[i - 1]) ? 0 : 1;

            int del = (j + 1 < dp_len) ? dp_prev[j + 1] + 1 : inf;
            int ins = (0 < j) ? dp_cur[j - 1] + 1 : inf;
            int sub = dp_prev[j] + cost;

            dp_cur[j] = minOf3(del, ins, sub);
        }

        int* temp = dp_prev;
        dp_prev = dp_cur;
        dp_cur = temp;
    }

    ans = dp_prev[(0 <= k + n - m) ? k + n - m : 0];
    ans = k + n - m;
    if (ans < 0 || dp_len <= ans || k < dp_prev[ans]) {
        fputs("-1", stdout);
    }
    else {
        printf("%d", dp_prev[ans]);
    }

cleanup:
    if (a) free(a);
    if (b) free(b);
    if (dp_prev) free(dp_prev);
    if (dp_cur) free(dp_cur);

    return result;
}
