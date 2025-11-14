#pragma once
#define SEGMENTTREE_H

typedef struct {
	int* tree;
	int* lazy;
	int size;
} SegmentTree;

SegmentTree* segmentTree_create(int size);
void segmentTree_destroy(SegmentTree* st);

void segmentTree_apply(SegmentTree* st, int v, int l, int r, int val);
void segmentTree_push(SegmentTree* st, int v, int l, int r);
void segmentTree_update(SegmentTree* st, int v, int l, int r, int L, int R, int x);
int segmentTree_query(SegmentTree* st, int v, int l, int r, int i);