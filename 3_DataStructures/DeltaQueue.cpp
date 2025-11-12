#include <stdio.h>
#include "../DataStructures/Dequeue.h"
#include "../DataStructures/Queue.h"
#include "3_DataStructures.h"

int DeltaQueue() {
	int cap = 200000;

	Queue* que = queue_create(cap);
	Dequeue* maxDeq = dequeue_create(cap);
	Dequeue* minDeq = dequeue_create(cap);

	int n;
	scanf_s("%d\n", &n);

	while (n--) {
		int x;
		scanf_s("%d", &x);

		if (x == -1) {
			int a = queue_pop(que);
			int max = dequeue_peek_front(maxDeq);
			int min = dequeue_peek_front(minDeq);

			if (max == a) pop_front(maxDeq);
			if (min == a) pop_front(minDeq);
		}
		else {
			queue_push(que, x);

			int c;
			while ((c = dequeue_peek_back(maxDeq)) != -1 && c < x) pop_back(maxDeq);
			push_back(maxDeq, x);

			while ((c = dequeue_peek_back(minDeq)) != -1 && x < c) pop_back(minDeq);
			push_back(minDeq, x);
		}

		int diff = dequeue_peek_front(maxDeq) - dequeue_peek_front(minDeq);
		printf(" %d", que->size ? diff : -1);
	}

	return 0;
}