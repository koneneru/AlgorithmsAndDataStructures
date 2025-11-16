#include <stdlib.h>
#include "Stack.h"

Stack* stack_create(const int capacity) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack == NULL) return NULL;

	stack->data = (int*)malloc(capacity * sizeof(int));
	stack->capacity = capacity;
	stack->size = 0;

	return stack;
}

void stack_destroy(Stack* s) {
	free(s->data);
	free(s);
}

void stack_push(Stack* stack, const int value) {
	stack->data[stack->size++] = value;
}

int stack_pop(Stack* stack) {
	if (stack->size == 0) return -1;

	return stack->data[--stack->size];
}

int stack_peek(Stack* stack) {
	if (stack->size == 0) return -1;

	return stack->data[stack->size - 1];
}