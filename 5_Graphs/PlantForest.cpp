#include <stdio.h>
#include "5_Graphs.h"

int PlantForest()
{
	int A[42][42] = { 0 };
	int n, k;
	scanf_s("%d %d", &n, &k);

	for (int i = k - 1; i < n; i++) {
		A[i][i + 1] = 1;
		A[i + 1][i] = 1;
	}

	for (int i = 0; i < n; i++) {
		if (i) putchar('\n');
		for (int j = 0; j < n; j++) {
			if (j) putchar(' ');
			printf("%d", A[i][j]);
		}
	}

	return 0;
}
