#include <stdio.h>

int KnightsMove() {
	int n, m;;
	scanf_s("%d %d", &n, &m);

	int arr[50][50] = { 0 };
	arr[0][0] = 1;
	arr[1][2] = 1;
	arr[2][1] = 1;

	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			arr[i][j] = arr[i - 1][j - 2] + arr[i - 2][j - 1];
		}
	}

	printf("%d", arr[n - 1][m - 1]);

	return 0;
}