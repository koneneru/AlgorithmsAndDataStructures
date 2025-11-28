#include <stdio.h>
#include "5_Graphs.h"

int LoopsAndMultipleEdgesInGraph()
{
	int A[32][32] = { 0 };
	int n, m;
	scanf_s("%d\n%d", &n, &m);

	int a[1000] = { 0 };
	int b[1000] = { 0 };
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &a[i], &b[i]);
	}

	int s = 0;
	int S[1000] = { 0 };
	for (int i = 0; i < m; i++) {
		int ai = a[i];
		int bi = b[i];
		if (ai == bi) {
			A[ai - 1][bi - 1]++;
			S[s++] = i + 1;
		}
		else {
			A[ai - 1][bi - 1]++;
			A[bi - 1][ai - 1]++;
		}
	}
	int p = 0;
	int P[1000] = { 0 };
	for (int i = 0; i < m; i++) {
		int ai = a[i] - 1;
		int bi = b[i] - 1;
		if (1 < A[ai][bi]) {
			P[p++] = i + 1;
		}
	}

	printf("%d selfloops\n", s);
	for (int i = 0; i < s; i++) {
		if (i) putchar(' ');
		printf("%d", S[i]);
	}
	putchar('\n');

	printf("%d parallel edges\n", p);
	for (int i = 0; i < p; i++) {
		if (i) putchar(' ');
		printf("%d", P[i]);
	}

	return 0;
}
