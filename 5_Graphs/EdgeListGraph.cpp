#include <stdio.h>
#include "5_Graphs.h"

int EdgeListGraph()
{
	int A[32][32] = { 0 };
	int I[32][500] = { 0 };
	int n, m;
	scanf_s("%d\n%d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);
		A[a - 1][b - 1]++;
		A[b - 1][a - 1]++;
		I[a - 1][i] = 1;
		I[b - 1][i] = 1;
	}

	puts("ADJACENCY MATRIX");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j) putchar(' ');
			printf("%d", A[i][j]);
		}
		putchar('\n');
	}

	puts("INCIDENCE MATRIX");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j) putchar(' ');
			printf("%d", I[i][j]);
		}
		putchar('\n');
	}

	puts("ADJACENCY LISTS");
	for (int i = 0; i < n; i++) {
		printf("%d =>", i + 1);
		for (int j = 0; j < n; j++) {
			if (A[i][j]) printf(" %d", j + 1);
		}
		putchar('\n');
	}

	return 0;
}
