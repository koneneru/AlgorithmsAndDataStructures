#pragma once
#define STACK_H

typedef struct {
	int* data;
	int capacity;
	int size;
} Stack;

Stack* stack_create(const int capacity);
void stack_destroy(Stack* deq);

void push(Stack* stack, const int value);
int pop(Stack* stack);
int peek(Stack* stack);