#pragma once
#define FEWICKTREE_H

typedef struct {
	int* data;
	int size;
} FenwickTree;

FenwickTree* fenwick_create(int size);
void fenwick_destroy(FenwickTree* ft);

void fenwick_add(FenwickTree* ft, int i, const int val);
int fenwick_sum(FenwickTree* ft, int i);
int fenwick_range_sum(FenwickTree* ft, int l, int r);