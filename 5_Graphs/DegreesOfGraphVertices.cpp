#include <stdio.h>
#include "5_Graphs.h"

int DegreesOfGraphVertices()
{
	int a[2][32] = { 0 };
	int n;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int b;
			scanf_s("%d", &b);
			if (b) {
				a[0][j]++;
				a[1][i]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (i) putchar('\n');
		printf("Vertex %d: in degree = %d, out degree = %d", i + 1, a[0][i], a[1][i]);
	}

	return 0;
}
