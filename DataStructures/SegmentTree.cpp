#include <stdlib.h>
#include "SegmentTree.h"

SegmentTree* segmentTree_create(int size) {
	SegmentTree* st = (SegmentTree*)malloc(sizeof(SegmentTree));
	if (st == NULL) return NULL;

	st->tree = (int*)calloc((size << 2), sizeof(int));
	st->lazy = (int*)calloc((size << 2), sizeof(int));
	st->size = size;

	return st;
}

void segmentTree_destroy(SegmentTree* st) {
	free(st->tree);
	free(st->lazy);
	free(st);
}

void segmentTree_apply(SegmentTree* st, int v, int l, int r, int val) {
	st->tree[v] = val;
	st->lazy[v] = val;
}

void segmentTree_push(SegmentTree* st, int v, int l, int r) {
	if (st->lazy[v] == -1 || l == r) return;

	int mid = (l + r) >> 1;
	segmentTree_apply(st, v << 1, l, mid, st->lazy[v]);
	segmentTree_apply(st, (v << 1) + 1, mid + 1, r, st->lazy[v]);
	st->lazy[v] = -1;
}

void segmentTree_update(SegmentTree* st, int v, int l, int r, int L, int R, int x) {
	if (R < l || r < L) return;
	if (L <= l && r <= R) {
		segmentTree_apply(st, v, l, r, x);
		return;
	}

	segmentTree_push(st, v, l, r);
	int mid = (l + r) >> 1;
	segmentTree_update(st, v << 1, l, mid, L, R, x);
	segmentTree_update(st, (v << 1) + 1, mid + 1, r, L, R, x);
}

int segmentTree_query(SegmentTree* st, int v, int l, int r, int i) {
	if (l == r) return st->lazy[v];

	segmentTree_push(st, v, l, r);
	int mid = (l + r) >> 1;
	if (i <= mid) return segmentTree_query(st, v << 1, l, mid, i);
	else return segmentTree_query(st, (v << 1) + 1, mid + 1, r, i);
}
