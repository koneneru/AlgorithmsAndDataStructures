#include <stdio.h>
#include <limits.h>

int prima(int (*adj)[100], int n) {
    int used[101] = { 0 };
    int min_edge[101] = { 0 };
    for (int i = 1; i <= n; i++) min_edge[i] = INT_MAX;
    min_edge[1] = 0;

    int result = 0;
    for (int i = 1; i <= n; i++) {
        int v = -1;
        for (int j = 1; j <= n; j++) {
            if (!used[j] && (v == -1 || min_edge[j] < min_edge[v])) v = j;
        }

        if (min_edge[v] == INT_MAX) return 0;

        used[v] = 1;
        result += min_edge[v];

        for (int j = 1; j <= n; j++) {
            if (!used[j] && adj[v][j] && adj[v][j] < min_edge[j])
                min_edge[j] = adj[v][j];
        }
    }

    return result;
}

int PurePrima() {
    int adj[100][100] = { 0 };
    int n, m;
    scanf_s("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf_s("%d %d %d", &a, &b, &c);
        adj[a][b] = c;
        adj[b][a] = c;
    }

    printf("%d\n", prima(adj, n));

    return 0;
}