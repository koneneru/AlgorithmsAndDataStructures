#include <stdio.h>
#include <stdlib.h>
#include "../DataStructures/Stack.h"
#include "../Sort/Sort.h"
#include "3_DataStructures.h"

int LargeLinearCollider() {
	int n;
	scanf_s("%d", &n);

	Stack* stack = stack_create(n);
	int* events = (int*)calloc(n >> 1, sizeof(int));
	if (events == NULL) {
		printf("memory allocation faild");
		return 1;
	}

	int ei = 0;

	for (int i = 0; i < n; i++) {
		int x, v;
		scanf_s("%d %d", &x, &v);

		if (v == 1) {
			stack_push(stack, x);
		}
		else {
			if (stack->size) {
				int p = stack_pop(stack);

				events[ei++] = (x - p + 1) >> 1;
			}
		}
	}

	int* buf = (int*)calloc(n >> 1, sizeof(int));
	mergeSort(events, buf, 0, ei - 1);

	int q, ectn = 0;
	scanf_s("%d", &q);
	while (q--) {
		int t;
		scanf_s("%d", &t);

		while (ectn < ei && events[ectn] <= t) ectn++;

		printf("%d ", n - (ectn << 1));
	}

	free(events);
	free(buf);
	stack_destroy(stack);

	return 0;
}