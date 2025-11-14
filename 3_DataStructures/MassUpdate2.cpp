#include <stdio.h>
#include "../DataStructures/SegmentTree.h"
#include "3_DataStructures.h"

int MassUpdate2() {
	int n, q;
	scanf_s("%d %d", &n, &q);

	SegmentTree* st = segmentTree_create(n);

	while (q--) {
		char c;
		scanf_s(" %c", &c, 1);

		if (c == '=') {
			int l, r, x;
			scanf_s("%d %d %d", &l, &r, &x);
			segmentTree_update(st, 1, 1, st->size, l, r, x);
		}
		else {
			int i;
			scanf_s("%d", &i);
			printf("%d\n", segmentTree_query(st, 1, 1, st->size, i));
		}
	}

	segmentTree_destroy(st);

	return 0;
}