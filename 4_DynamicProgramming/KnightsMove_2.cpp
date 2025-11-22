#include <stdio.h>
#include "4_DynamicProgramming.h"

int KnightsMove_2() {
	int n, m;;
	scanf_s("%d %d", &n, &m);

	long long arr[22][22] = { 0 };
	arr[1][1] = 1ll;

	for (int k = 2; k <= n + m; k++) {
		for (int i = 0; i <= n; i++) {
			int j = k - i;
			if (j < 1 || m < j) continue;

			if (1 <= i - 2 && j + 1 <= m) arr[i][j] += arr[i - 2][j + 1];
			if (1 <= i - 2 && 1 <= j - 1) arr[i][j] += arr[i - 2][j - 1];

			if (1 <= j - 2 && i + 1 <= n) arr[i][j] += arr[i + 1][j - 2];
			if (1 <= j - 2 && 1 <= i - 1) arr[i][j] += arr[i - 1][j - 2];
		}
	}

	printf("%lld", arr[n][m]);

	return 0;
}