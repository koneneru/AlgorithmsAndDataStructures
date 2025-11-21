#include <stdio.h>
#include <stdlib.h>
#include "2_SortAndFind.h"

int KthOrdinalStatistics()
{
    int n, k, m;
    scanf_s("%d %d %d", &n, &k, &m);
    long long a, b, c;
    scanf_s("%lld %lld %lld", &a, &b, &c);

    int* arr = (int*)malloc(m * sizeof(int));
    if (arr == NULL) {
        puts("memory allocation failed");
        return 1;
    }
    for (int i = 0; i < m; i++) scanf_s("%d", &arr[i]);

    int mask = 0;
    for (int shift = 31; 0 <= shift; shift--) {
        int ctn0 = 0;
        int ctn1 = 0;

        // ==========
        for (int i = 0; i < m; i++) {
            int x = arr[i] ^ mask;
            if ((x >> shift) == 0) ctn0++;
            else ctn1++;
        }

        int p1 = arr[m - 1];
        int p2 = arr[m - 2];

        for (int i = m; i < n; i++) {
            long long z = a * p2 + b * p1 + c;
            int x = (int)((unsigned int)z);

            p2 = p1;
            p1 = x;

            x ^= mask;
            if ((x >> shift) == 0) {
                ctn0++;
            }
            else ctn1++;

        }
        // =========

        if (shift == 31) {
            if (k <= ctn1) mask |= (1u << shift);
            else k -= ctn1;
        }

        if (ctn0 < k) {
            k -= ctn0;
            mask |= (1u << shift);
        }
    }

    printf("%d", mask);

    free(arr);

    return 0;
}

