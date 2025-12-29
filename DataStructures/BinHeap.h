#pragma once
#define BINHEAP_H

typedef struct {
	int x, y, f;
} HeapItem;

typedef struct {
	HeapItem* data;
	int size;
	int capacity;
} BinHeap;

BinHeap* binHeap_create(int cap);
void binHeap_destroy(BinHeap* heap);

void swap(HeapItem* a, HeapItem* b);
void binHeap_push(BinHeap* heap, HeapItem item);
int binHeap_pop(BinHeap* heap, HeapItem* target);