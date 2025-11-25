#include <stdio.h>
#include <limits.h>
#include "4_DynamicProgramming.h"

int Data2ItemSets() {
	int n;
	scanf_s("%d", &n);

	long long A = 0ll;
	int p[1501] = { 0 };
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);
		p[i] = a + b;
		A += a;
	}

	long long dp[1501];
	for (int i = 1; i <= n; i++) {
		dp[i] = LLONG_MAX - (10000 << 1);
	}
	dp[0] = 0ll;

	for (int i = 0; i < n; i++) {
		for (int j = n; 1 <= j; j--) {
			if (dp[j - 1] + p[i] < dp[j]) {
				dp[j] = dp[j - 1] + p[i];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (dp[i] <= A) ans = i;
	}

	printf("%d", ans);

	return 0;
}