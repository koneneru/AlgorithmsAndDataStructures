#include <stdio.h>
#include <limits.h>

int dijkstra(int (*adj)[100], int n) {
    int used[101] = { 0 };
    int dist[101] = { 0 };
    for (int i = 0; i <= n; i++) dist[i] = INT_MAX;
    dist[1] = 0;

    for (int i = 1; i <= n; i++) {
        int v = -1;
        for (int j = 1; j <= n; j++) {
            if (!used[j] && (v == -1 || dist[j] < dist[v])) v = j;
        }

        if (dist[v] == INT_MAX) break;

        used[v] = 1;

        for (int j = 1; j <= n; j++) {
            if (adj[v][j] != 0 && dist[v] + adj[v][j] < dist[j])
                dist[j] = dist[v] + adj[v][j];
        }
    }

    return dist[n];
}

int PureDijkstra() {
    int adj[100][100] = { 0 };
    int n, m;
    scanf_s("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf_s("%d %d %d", &a, &b, &c);
        adj[a][b] = c;
        adj[b][a] = c;
    }

    int ans = dijkstra(adj, n);

    printf("%d\n", ans != INT_MAX ? ans : 0);

    return 0;
}