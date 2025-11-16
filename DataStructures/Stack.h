#pragma once
#define STACK_H

typedef struct {
	int* data;
	int capacity;
	int size;
} Stack;

Stack* stack_create(const int capacity);
void stack_destroy(Stack* deq);

void stack_push(Stack* stack, const int value);
int stack_pop(Stack* stack);
int stack_peek(Stack* stack);