#include <stdlib.h>
#include <string.h>
#include "GenericStack.h"

int stack_init(TStack* s, const size_t elemSize) {
	s->elemSize = elemSize;
	s->capacity = 4;
	s->top = -1;
	s->data = malloc(s->capacity * s->elemSize);
	if (s->data == NULL) {
		return 1;
	}

	return 0;
}

void stack_free(TStack* s) {
	if (s == NULL) return;

	free(s->data);
	s->data = NULL;
	s->elemSize = 0;
	s->capacity = 0;
	s->top = -1;
}

int stack_push(TStack* s, const void* val) {
	if (s->top + 1 == s->capacity) {
		s->capacity <<= 1;
		void* temp = realloc(s->data, s->capacity * s->elemSize);
		if (!temp) return 1;

		s->data = temp;
	}

	s->top++;
	void* target = (char*)s->data + (s->top * s->elemSize);
	memcpy(target, val, s->elemSize);
}

void stack_pop(TStack* s, void* target) {
	if (s->top == -1) return;

	void* source = (char*)s->data + (s->top * s->elemSize);
	if (target != NULL) {
		memcpy(target, source, s->elemSize);
	}
	s->top--;

}

void stack_peek(TStack* s, void* target) {
	if (s->top == -1) return;

	void* source = (char*)s->data + (s->top * s->elemSize);
	if (target != NULL) {
		memcpy(target, source, s->elemSize);
	}
}