#pragma once
#define DEQUEUE_H

typedef struct {
	int* data;
	int capacity;
	int head;
	int tail;
	int size;
} Dequeue;

Dequeue* dequeue_create(const int capacity);
void dequeue_destroy(Dequeue* deq);

void push_back(Dequeue* deq, const int value);
int pop_back(Dequeue* deq);
void push_front(Dequeue* deq, const int value);
int pop_front(Dequeue* deq);