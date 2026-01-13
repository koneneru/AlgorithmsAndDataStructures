#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char lat[16];
    char eng[16];
} WordPair;

int comparePairs(const void* a, const void* b) {
    WordPair* p1 = (WordPair*)a;
    WordPair* p2 = (WordPair*)b;
    int res = strcmp(p1->lat, p2->lat);
    if (res == 0)
        return strcmp(p1->eng, p2->eng);
    return res;
}

char* readLine() {
    int cap = 16;
    int len = 0;
    char* buf = (char*)malloc(cap);
    if (!buf) {
        fprintf(stderr, "memory allocation failed");
        exit(1);
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        buf[len++] = c;

        if (len == cap - 1) {
            cap = cap < 1024 ? (cap << 2) : (cap + (cap >> 2));
            buf = (char*)realloc(buf, cap);
            if (!buf) {
                fprintf(stderr, "memory allocation failed");
                exit(1);
            }
        }
    }
    buf[len] = '\0';
    return buf;
}

int EnglishLatinDictionary() {
    int n;
    scanf_s("%d\n", &n);

    WordPair* pairs = (WordPair*)malloc(200000 * sizeof(WordPair));
    if (!pairs) {
        fprintf(stderr, "memory allocation failed");
        return 1;
    }
    int pairCnt = 0;

    for (int i = 0; i < n; i++) {
        char* line = readLine();

        char* dash = strstr(line, " - ");
        if (!dash) continue;
        *dash = '\0';

        char* eng = line;
        char* latList = dash + 3;

        char* lat = strtok(latList, ", ");
        while (lat != NULL) {
            strcpy(pairs[pairCnt].eng, eng);
            strcpy(pairs[pairCnt].lat, lat);
            pairCnt++;
            lat = strtok(NULL, ", ");
        }
    }

    qsort(pairs, pairCnt, sizeof(WordPair), comparePairs);

    int uniqueLat = 1;
    for (int i = 1; i < pairCnt; i++) {
        if (strcmp(pairs[i].lat, pairs[i - 1].lat) != 0)
            uniqueLat++;
    }

    printf("%d\n", uniqueLat);

    for (int i = 0; i < pairCnt; i++) {
        if (i == 0 || strcmp(pairs[i].lat, pairs[i - 1].lat) != 0) {
            if (i) putchar('\n');
            printf("%s - %s", pairs[i].lat, pairs[i].eng);
        }
        else {
            fputs(", ", stdout);
            fputs(pairs[i].eng, stdout);
        }
    }

    free(pairs);

    return 0;
}