#include <stdio.h>
#include <stdlib.h>
#include  "4_DynamicProgramming.h"

int Turtle_2() {
	int n, m;;
	scanf_s("%d\n%d", &n, &m);

	long long* arr1 = (long long*)malloc(m * sizeof(long long));
	long long* arr2 = (long long*)malloc(m * sizeof(long long));
	if (arr1 == NULL || arr2 == NULL) {
		puts("memory allocation failed");
		return 1;
	}
	for (int i = 0; i < m; i++) arr1[i] = 1;

	long long** a = &arr1;
	long long** b = &arr2;

	for (int i = 1; i < n; i++) {
		(*b)[0] = 1;
		for (int j = 1; j < m; j++) {
			(*b)[j] = (*a)[j] + (*b)[j - 1];
		}

		long long** temp = b;
		b = a;
		a = temp;
	}

	printf("%lld", (*a)[m - 1]);

	free(arr1);
	free(arr2);

	return 0;
}