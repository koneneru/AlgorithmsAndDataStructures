#include <stdio.h>
#include "5_Graphs.h"

int GraphByAdjacencyMatrix()
{
	int A[32][32] = { 0 };
	int I[32][500] = { 0 };
	int n, m = 0;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			scanf_s("%d", &a);
			A[i][j] = a;
			if (a && i < j) {
				I[i][m] = 1;
				I[j][m] = 1;
				m++;
			}
		}
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
