#include <stdio.h>

int NumberOfHamiltonianPaths()
{
	int A[8][8] = { 0 };

	int n;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &A[i][j]);
		}
	}

	int dp[1 << 8][8] = { 0 };
	for (int i = 0; i < n; i++) {
		dp[1 << i][i] = 1;
	}

	int maxMask = 1 << n;
	for (int mask = 0; mask < maxMask; mask++) {
		for (int v = 0; v < n; v++) {
			if (!(mask & (1 << v))) continue;

			int prevMask = mask ^ (1 << v);
			if (prevMask == 0) continue;

			for (int u = 0; u < n; u++) {
				if ((prevMask & (1 << u)) && A[u][v]) {
					dp[mask][v] += dp[prevMask][u];
				}
			}
		}
	}

	int ans = 0;
	int fullMask = maxMask - 1;
	for (int v = 0; v < n; v++) {
		ans += dp[fullMask][v];
	}

	printf("%d\n", ans);

	return 0;
}