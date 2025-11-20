#include <stdio.h>
#include <stdlib.h>
#include "2_SortAndFind.h"

int RadixSort()
{
    int n;
    scanf_s("%d", &n);

    char c[100] = { 0 };
    scanf_s("%s", &c, 100);

    int m = 0;
    while (c[m++] != '\0');

    char** a = (char**)malloc(n * sizeof(char*));
    if (a == NULL) {
        puts("memory allocation failed");
        return 1;
    }

    a[0] = (char*)calloc(m + 1, sizeof(char));
    if (a[0] == NULL) {
        puts("memory allocation failed");
        return 1;
    }

    for (int i = 0; i <= m; i++) a[0][i] = c[i];

    for (int i = 1; i < n; i++) {
        a[i] = (char*)calloc(m + 1, sizeof(char));
        if (a[i] == NULL) {
            puts("memory allocation failed");
            return 1;
        }

        scanf_s("%s", a[i], m + 1);
    }

    puts("Initial array:");
    for (int i = 0; i < n; i++) {
        if (i) fputs(", ", stdout);
        printf("%s", a[i]);
    }
    puts("\n**********");

    char** buf = (char**)malloc(n * sizeof(char*));
    if (buf == NULL) {
        puts("memory allocation failed");
        return 1;
    }
    for (int i = 0; i < n; i++) buf[i] = a[i];

    for (int phase = 1; phase < m; phase++) {
        printf("Phase %d\n", phase);

        char* bucket[10][1005] = { 0 };
        int count[10] = { 0 };

        int pos = m - phase - 1;

        for (int i = 0; i < n; i++) {
            int d = buf[i][pos] - '0';
            bucket[d][count[d]++] = buf[i];
        }

        int k = 0;
        for (int i = 0; i < 10; i++) {
            printf("Bucket %d: ", i);
            if (!count[i]) {
                puts("empty");
            }
            else {
                for (int j = 0; j < count[i]; j++) {
                    if (j) fputs(", ", stdout);
                    fputs(bucket[i][j], stdout);
                    buf[k++] = bucket[i][j];
                }
                putchar('\n');
            }
        }

        puts("**********");
    }

    puts("Sorted array:");
    for (int i = 0; i < n; i++) {
        if (i) fputs(", ", stdout);
        printf("%s", buf[i]);
    }

    free(buf);
    for (int i = 0; i < n; i++) free(a[i]);
    free(a);

    return 0;

}