#include <stdio.h>
#include <stdlib.h>
#include "2_SortAndFind.h"

void MergeSort(int* a, int* b, int l, int r) {
    if (r <= l) return;

    int m = (l + r) / 2;
    MergeSort(a, b, l, m);
    MergeSort(a, b, m + 1, r);

    int k = l;
    for (int i = l, j = m + 1; i <= m || j <= r;) {
        if (r < j || (i <= m && a[i] < a[j])) {
            b[k] = a[i++];
        }
        else {
            b[k] = a[j++];
        }
        k++;
    }

    for (int i = l; i <= r; i++) {
        a[i] = b[i];
    }
}

int OrganizationOfTournament()
{
    int n;
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        puts("memory allocation failed");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    int* buf = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        puts("memory allocation failed");
        return 1;
    }
    MergeSort(arr, buf, 0, n - 1);

    free(buf);

    int s = 0;
    for (int i = 1; i < n; i += 2) {
        s += arr[i] - arr[i - 1];
    }

    if (n % 2 == 1) {
        int ps, best;
        ps = best = s;
        for (int i = n - 2; 0 <= i; i--) {
            int cs;
            if (i % 2 == 0)
                cs = ps - (arr[i + 2] - arr[i]) + (arr[i + 2] - arr[i + 1]);
            else
                cs = ps - (arr[i] - arr[i - 1]) + (arr[i + 1] - arr[i - 1]);
            if (cs < best) best = cs;

            ps = cs;
        }
        s = best;
    }

    free(arr);

    printf("%d\n%d", n >> 1, s);

    return 0;
}

