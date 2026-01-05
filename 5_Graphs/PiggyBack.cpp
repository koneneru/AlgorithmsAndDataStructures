#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "5_Graphs.h"

typedef struct {
    int from;
    int to;
} Edge;

typedef struct {
    int n, m;
    int b, e, p;

    int edgeCnt;
    Edge* edges;
    int* head;
} Context;

void add_edge(Context* ctx, int u, int v) {
    ctx->edges[ctx->edgeCnt].from = v;
    ctx->edges[ctx->edgeCnt].to = ctx->head[u];
    ctx->head[u] = ctx->edgeCnt++;
}

void bfs(Context* ctx, int start, int* dist) {
    int* queue = (int*)malloc((ctx->n + 1) * sizeof(int));
    if (!queue) exit(1);

    int front = 0;
    int back = 0;

    for (int i = 1; i <= ctx->n; i++) dist[i] = INT_MAX;
    dist[start] = 0;

    queue[back++] = start;
    while (front < back) {
        int u = queue[front++];

        for (int e = ctx->head[u]; e != -1; e = ctx->edges[e].to) {
            int v = ctx->edges[e].from;
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                queue[back++] = v;
            }
        }
    }

    free(queue);
}

int PiggyBack() {
    Context ctx = {};

    scanf_s("%d %d %d %d %d", &ctx.b, &ctx.e, &ctx.p, &ctx.n, &ctx.m);

    ctx.edges = (Edge*)malloc((ctx.m << 1) * sizeof(Edge));
    ctx.head = (int*)malloc((ctx.n + 1) * sizeof(int));
    for (int i = 0; i <= ctx.n; i++) ctx.head[i] = -1;

    for (int i = 0; i < ctx.m; i++) {
        int u, v;
        scanf_s("%d %d", &u, &v);
        add_edge(&ctx, u, v);
        add_edge(&ctx, v, u);
    }

    int* d1 = (int*)malloc((ctx.n + 1) * sizeof(int));
    int* d2 = (int*)malloc((ctx.n + 1) * sizeof(int));
    int* dn = (int*)malloc((ctx.n + 1) * sizeof(int));
    if (!(d1 && d2 && dn)) return -1;

    bfs(&ctx, 1, d1);
    bfs(&ctx, 2, d2);
    bfs(&ctx, ctx.n, dn);

    long long ans = LLONG_MAX;

    for (int i = 1; i <= ctx.n; i++) {
        if (d1[i] == INT_MAX || d2[i] == INT_MAX || dn[i] == INT_MAX) continue;

        long long cost =
            (long long)d1[i] * ctx.b +
            (long long)d2[i] * ctx.e +
            (long long)dn[i] * ctx.p;

        if (cost < ans) ans = cost;
    }

    printf("%lld\n", ans);

    free(d1);
    free(d2);
    free(dn);
    free(ctx.head);
    free(ctx.edges);

    return 0;
}