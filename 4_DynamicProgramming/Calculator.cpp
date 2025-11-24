#include <stdio.h>
#include <stdlib.h>
#include "4_DynamicProgramming.h"

int Calculator()
{
    int n;
    scanf_s("%d", &n);

    int* dist = (int*)malloc((n + 1) * sizeof(int));
    int* prev = (int*)malloc((n + 1) * sizeof(int));
    if (dist == NULL || prev == NULL) {
        puts("memory allocation failed");
        return 1;
    }

    dist[0] = 0;
    dist[1] = 0;
    prev[1] = -1;

    for (int i = 2; i <= n; i++) {
        dist[i] = dist[i - 1] + 1;
        prev[i] = i - 1;

        if (i % 2 == 0) {
            if (dist[i >> 1] + 1 < dist[i]) {
                dist[i] = dist[i >> 1] + 1;
                prev[i] = i >> 1;
            }
        }

        if (i % 3 == 0) {
            if (dist[i / 3] + 1 < dist[i]) {
                dist[i] = dist[i / 3] + 1;
                prev[i] = i / 3;
            }
        }
    }

    int* path = (int*)malloc((dist[n] + 1) * sizeof(int));
    if (path == NULL) {
        puts("memory allocation failed");
        return 1;
    }

    for (int i = dist[n], cur = n; 0 <= i; i--) {
        path[i] = cur;
        cur = prev[cur];
    }

    printf("%d\n", dist[n]);
    for (int i = 0; i <= dist[n]; i++) {
        if (i) putchar(' ');
        printf("%d", path[i]);
    }

    free(path);
    free(prev);
    free(dist);

    return 0;
}
