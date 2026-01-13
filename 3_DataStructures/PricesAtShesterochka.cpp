#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[121];
    int price;
} PriceTag;

int comparePrices(const void* a, const void* b) {
    PriceTag* t1 = (PriceTag*)a;
    PriceTag* t2 = (PriceTag*)b;

    int res = strcmp(t1->name, t2->name);
    if (res != 0) return res;
    return t1->price - t2->price;;
}

int PricesAtShesterochka() {
    int n;
    scanf_s("%d\n", &n);

    PriceTag* priceList = (PriceTag*)malloc(n * sizeof(PriceTag));
    if (!priceList) {
        fprintf(stderr, "memory allocation failed");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf_s("%20s %d", &priceList[i].name, 21, &priceList[i].price);
    }

    qsort(priceList, n, sizeof(PriceTag), comparePrices);

    int prodCnt = 1;
    for (int i = 1; i < n; i++) {
        if (strcmp(priceList[i].name, priceList[i - 1].name) != 0)
            prodCnt++;
    }

    printf("%d\n", prodCnt);

    for (int i = 0; i < n; i++) {
        if (i && strcmp(priceList[i].name, priceList[i - 1].name) == 0) continue;
        printf("%s %d\n", priceList[i].name, priceList[i].price);
    }

    free(priceList);

    return 0;
}