#include <stdio.h>
#include "../DataStructures/Dequeue.h"
#include "3_DataStructures.h"

int GoblinsAndShamans() {
	int cap = 100000;
	Dequeue* deq1 = dequeue_create(cap);
	Dequeue* deq2 = dequeue_create(cap);

	int n;
	scanf_s("%d\n", &n);

	while (n--) {
		char c;
		scanf_s(" %c", &c, 1);

		if (c == 'C') {
			int p = pop_front(deq1);
			printf("%d\n", p != -1 ? p : pop_front(deq2));
			if (1 < deq2->size - deq1->size) {
				push_back(deq1, pop_front(deq2));
			}
		}
		else {
			int x;
			scanf_s("%d", &x);

			if (c == 'P') {
				push_back(deq2, x);
				if (1 < deq2->size - deq1->size) {
					push_back(deq1, pop_front(deq2));
				}
			}
			else {
				if (deq1->size == deq2->size) {
					push_front(deq2, x);
				}
				else
				{
					push_back(deq1, pop_front(deq2));
					push_front(deq2, x);
				}
			}
		}
	}

	return 0;
}