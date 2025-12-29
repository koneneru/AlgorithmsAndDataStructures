#include <stdlib.h>
#include "BinHeap.h"

BinHeap* binHeap_create(int cap) {
	BinHeap* heap = (BinHeap*)malloc(sizeof(BinHeap));
	if (!heap) return NULL;

	heap->data = (HeapItem*)malloc(sizeof(HeapItem) * cap);
	heap->size = 0;
	heap->capacity = cap;

	return heap;
}

void binHeap_destroy(BinHeap* heap) {
	free(heap->data);
	free(heap);
}

void swap(HeapItem* a, HeapItem* b) {
	HeapItem temp = *a;
	*a = *b;
	*b = temp;
}

void binHeap_push(BinHeap* heap, HeapItem item) {
	heap->data[heap->size] = item;
	int i = heap->size++;
	while (0 < i && heap->data[i].f < heap->data[(i - 1) >> 1].f) {
		swap(&heap->data[i], &heap->data[(i - 1) >> 1]);
		i = (i - 1) >> 1;
	}
}

int binHeap_pop(BinHeap* heap, HeapItem* target) {
	if (target == NULL || heap->size == 0) return 0;

	*target = heap->data[0];
	heap->data[0] = heap->data[--heap->size];
	int i = 0;
	while ((i << 1) + 1 < heap->size) {
		int child = (i << 1) + 1;
		if (child + 1 < heap->size && heap->data[child + 1].f < heap->data[child].f) {
			child++;
		}
		if (heap->data[i].f <= heap->data[child].f) break;
		swap(&heap->data[i], &heap->data[child]);
		i = child;
	}

	return 1;
}