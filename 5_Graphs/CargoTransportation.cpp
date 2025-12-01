#include <stdio.h>
#include "5_Graphs.h"

int CargoTransportation()
{
	int A[100][100] = { 0 };
	int n, a, b, m;
	scanf_s("%d %d %d %d", &n, &a, &b, &m);
	a--;
	b--;

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);

		A[a - 1][b - 1] = 1;
		A[b - 1][a - 1] = 1;
	}

	int q[100];
	int head = 0, tail = 0;
	int visited[100] = { 0 };

	q[tail++] = a;
	visited[a] = 1;

	while (head < tail) {
		int v = q[head++];
		if (v == b) break;
		for (int i = 0; i < n; i++) {
			if (A[v][i] && !visited[i]) {
				visited[i] = 1;
				q[tail++] = i;
			}
		}
	}

	if (visited[b]) puts("Yes");
	else puts("No");

	return 0;
}
