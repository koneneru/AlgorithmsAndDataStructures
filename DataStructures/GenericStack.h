#pragma once
#define GENERICSTACK_H

typedef struct {
	void* data;
	size_t elemSize;
	int capacity;
	int top;
} TStack;

int stack_init(TStack* s, const size_t elemSize);
void stack_free(TStack* s);

int stack_push(TStack* s, const void* val);
void stack_pop(TStack* s, void* target);
void stack_peek(TStack* s, void* target);
