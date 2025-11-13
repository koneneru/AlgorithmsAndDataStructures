#include <stdio.h>
#include <stdlib.h>
#include "../DataStructures/FewickTree.h"
#include "3_DataStructures.h"

int SumOverChangingSegment() {
	int n;
	scanf_s("%d", &n);

	FenwickTree* ft = fenwick_create(n + 1);
	int* a = (int*)malloc((n + 1) * sizeof(int));
	if (a == NULL) {
		printf("memory allocation failed");
		return 1;
	}

	for (int i = 1; i <= n; i++) {
		int x;
		scanf_s("%d", &x);
		a[i] = x;
		fenwick_add(ft, i, x);
	}

	int q;
	scanf_s("%d", &q);
	while (q--) {
		char op;
		scanf_s(" %c", &op, 1);

		if (op == 'S') {
			int l, r;
			scanf_s("%d %d", &l, &r);
			printf("%d\n", fenwick_range_sum(ft, l, r));
		}
		else {
			int p, v;
			scanf_s("%d %d", &p, &v);
			int diff = v - a[p];
			a[p] = v;
			fenwick_add(ft, p, diff);
		}
	}

	fenwick_destroy(ft);
	free(a);

	return 0;
}