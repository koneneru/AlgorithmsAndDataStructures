#include <stdio.h>
#include "5_Graphs.h"

void dfs(int v, int* visited, int n, int (*adj)[32]) {
	visited[v] = 1;
	for (int i = 0; i < n; i++) {
		if (adj[v][i] && !visited[i]) {
			dfs(i, visited, n, adj);
		}
	}
}

int isConnected(int n, int (*adj)[32]) {
	int visited[32] = { 0 };
	dfs(0, visited, n, adj);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) return 0;
	}

	return 1;
}

int EncyclopediaOfSimpleGraphs()
{
	int adj[32][32] = { 0 };
	int deg[32] = { 0 };

	int n;
	scanf_s("%d", &n);

	int edges = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &adj[i][j]);
			if (adj[i][j]) {
				deg[i]++;
				edges++;
			}
		}
	}
	edges >>= 1;

	if (edges == 0) {
		puts("EMPTY");
		return 0;
	}

	int degCnt[32] = { 0 };
	for (int i = 0; i < n; i++) degCnt[deg[i]]++;

	if (degCnt[n - 1] == n) {
		puts("CLIQUE");
		return 0;
	}

	if (degCnt[1] == n) {
		puts("MATCHING");
		return 0;
	}

	if (degCnt[n - 1] == 1 && degCnt[1] == n - 1) {
		puts("STAR");
		return 0;
	}

	if (degCnt[3] == n) {
		puts("CUBIC");
		return 0;
	}
	int connected = isConnected(n, adj);
	if (connected && degCnt[2] == n) {
		puts("LOOP");
		return 0;
	}

	if (connected && degCnt[1] == 2 && degCnt[2] == n - 2) {
		puts("BAMBOO");
		return 0;
	}

	if (connected && edges == n - 1) {
		if (degCnt[1] && degCnt[3] && degCnt[1] + degCnt[3] == n) {
			puts("BINARY TREE");
			return 0;
		}
	}

	for (int i = 2; i <= (n >> 1); i++) {
		int j = n - i;
		if (edges == i * j) {
			if (i == j) {
				if (degCnt[i] == n) {
					puts("CUT");
					return 0;
				}
			}
			else {
				if (degCnt[i] == j && degCnt[j] == i) {
					puts("CUT");
					return 0;
				}
			}
		}
	}

	puts("OTHER");

	return 0;
}