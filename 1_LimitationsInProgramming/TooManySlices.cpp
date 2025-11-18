#include <stdio.h>
#include <stdlib.h>
#include "../common.h"
#include "1_LimitationsInProgramming.h"

int TooManySlices() {
	int n, q;
	scanf_s("%d%d", &n, &q);

	int* a = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}

	int L = 0, Len = n, S = 1;
	while (q--) {
		int l, r, s;
		scanf_s("%d%d%d", &l, &r, &s);
		L += l * S;
		S *= s;
		Len = (r - l - 1) / s + 1;
	}

	printf("%d\n", Len);
	if (0 < Len) {
		for (int i = 0; i < Len; i++) {
			if (i) putchar(' ');
			printf("%d", a[L + i * S]);
		}
	}

	free(a);

	return 0;
}