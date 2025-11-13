#include <stdlib.h>
#include "FewickTree.h"

FenwickTree* fenwick_create(int size) {
	FenwickTree* ft = (FenwickTree*)malloc(sizeof(FenwickTree));
	if (ft == NULL) return NULL;

	ft->data = (int*)calloc(size, sizeof(int));
	ft->size = size;

	return ft;
}

void fenwick_destroy(FenwickTree* ft) {
	free(ft->data);
	free(ft);
}

void fenwick_add(FenwickTree* ft, int i, const int val) {
	while (i < ft->size) {
		ft->data[i] += val;
		i += i & -i;
	}
}

int fenwick_sum(FenwickTree* ft, int i) {
	int s = 0;
	while (0 < i) {
		s += ft->data[i];
		i -= i & -i;
	}

	return s;
}

int fenwick_range_sum(FenwickTree* ft, int l, int r) {
	return fenwick_sum(ft, r) - fenwick_sum(ft, l - 1);
}