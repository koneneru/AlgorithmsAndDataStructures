#include <stdlib.h>
#include "Dequeue.h"

Dequeue* dequeue_create(int capacity) {
	Dequeue* deq = (Dequeue*)malloc(sizeof(Dequeue));
	if (deq == NULL) return NULL;

	deq->data = (int*)malloc(capacity * sizeof(int));
	deq->capacity = capacity;
	deq->head = 0;
	deq->tail = 0;
	deq->size = 0;

	return deq;
}

void dequeue_destroy(Dequeue* deq) {
	free(deq->data);
	free(deq);
}

void push_back(Dequeue* deq, const int value) {
	deq->data[deq->tail] = value;
	deq->tail = (deq->tail + 1) % deq->capacity;

	deq->size++;
}

int pop_back(Dequeue* deq) {
	if (deq->size == 0) return -1;

	deq->tail = (deq->tail - 1 + deq->capacity) % deq->capacity;

	deq->size--;

	return deq->data[deq->tail];
}

void push_front(Dequeue* deq, const int value) {
	deq->head = (deq->head - 1 + deq->capacity) % deq->capacity;
	deq->data[deq->head] = value;

	deq->size++;
}

int pop_front(Dequeue* deq) {
	if (deq->size == 0) return -1;

	int r = deq->data[deq->head];
	deq->head = (deq->head + 1) % deq->capacity;

	deq->size--;

	return r;
}