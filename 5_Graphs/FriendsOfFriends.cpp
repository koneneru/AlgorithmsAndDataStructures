#include <stdio.h>
#include "5_Graphs.h"

int FriendsOfFriends()
{
	int A[51][51] = { 0 };
	int g[51] = { 0 };
	int n, m;
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);

		A[a][g[a]++] = b;
		A[b][g[b]++] = a;
	}

	int dist[51] = { 0 };
	for (int i = 1; i <= n; i++) {
		dist[i] = -1;
	}

	int head = 0, tail = 0;
	dist[1] = 0;
	int q[51] = { 0 };
	q[tail++] = 1;

	while (head < tail) {
		int v = q[head++];
		for (int i = 0; i < g[v]; i++) {
			int u = A[v][i];
			if (dist[u] == -1) {
				dist[u] = dist[v] + 1;
				q[tail++] = u;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int first = 1;
		for (int j = 2; j <= n; j++) {
			if (dist[j] == i) {
				if (first) {
					if (1 < i) putchar('\n');
					printf("%d =>", i);
					first = 0;
				}
				printf(" %d", j);
			}
		}
	}

	return 0;
}
