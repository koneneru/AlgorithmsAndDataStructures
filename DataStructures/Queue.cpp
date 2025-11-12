#include <stdlib.h>
#include "Queue.h"

Queue* queue_create(int capacity) {
	Queue* que = (Queue*)malloc(sizeof(Queue));
	if (que == NULL) return NULL;

	que->data = (int*)malloc(capacity * sizeof(int));
	que->capacity = capacity;
	que->head = 0;
	que->tail = 0;
	que->size = 0;

	return que;
}

void queue_destroy(Queue* que) {
	free(que->data);
	free(que);
}

void queue_push(Queue* que, const int value) {
	que->data[que->tail] = value;
	que->tail = (que->tail + 1) % que->capacity;

	que->size++;
}

int queue_pop(Queue* que) {
	if (que->size == 0) return -1;

	int r = que->data[que->head];
	que->head = (que->head + 1) % que->capacity;

	que->size--;

	return r;
}