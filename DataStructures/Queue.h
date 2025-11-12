#pragma once
#define QUEUE_H

typedef struct {
	int* data;
	int capacity;
	int size;
	int head;
	int tail;
} Queue;

Queue* queue_create(int capacity);
void queue_destroy(Queue* que);

void queue_push(Queue* que, const int value);
int queue_pop(Queue* que);