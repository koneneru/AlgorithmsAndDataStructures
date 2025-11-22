#include <stdio.h>
#include "4_DynamicProgramming.h"

int ThreeOnesInRow() {
	int n;
	scanf_s("%d", &n);

	int T[3] = { 1, 2, 4 };

	for (int i = 2; i < n; i++) {
		int t = T[2] + T[1] + T[0];
		T[0] = T[1];
		T[1] = T[2];
		T[2] = t;
	}

	printf("%d", n < 3 ? T[n] : T[2]);

	return 0;
}