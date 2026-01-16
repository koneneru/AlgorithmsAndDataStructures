#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int isDigit(char c) {
    return '0' <= c && c <= '9';
}

int DroidNumbering() {
    int n;
    scanf_s("%d", &n);

    char* s = (char*)malloc((n + 1) * sizeof(char));
    if (!s) return 1;

    scanf_s("%s", s, n + 1);

    ll ans = 2ll;

    for (int i = 0; i < n; i++) {
        if (s[i] != '1') ans++;
        if (s[i] != 'A') ans++;
        if ('A' <= s[i] && s[i] < 'Z') ans++;
    }

    for (int i = 0; i < n;) {
        if (!isDigit(s[i])) {
            i++;
            continue;
        }

        int j = i;
        while (j < n && isDigit(s[j])) j++;

        int k = i;
        while (k < j) {
            if (s[k] == '9') {
                int start9 = k;
                while (k < j && s[k] == '9') k++;
                int p = k - start9;
                ans += ((ll)p * (p + 1)) >> 1;
            }
            else {
                int t = k + 1;
                while (t < j && s[t] == '9') t++;

                ans += t - k;
                k++;
            }
        }
        i = j;
    }

    printf("%lld", ans);

    free(s);

    return 0;
}