#include <stdio.h>
#include <stdlib.h>
#include "3_DataStructures.h"

int DnaReconstruction() {
	int n;
	scanf_s("%d\n", &n);

	char** pieces = (char**)malloc((n + 1) * sizeof(char*));
	char* input = (char*)malloc(1000000 + n);
	char* inputStr = input;
	for (int i = 1; i <= n; i++) {
		char c;
		int len = 0;
		while ((c = getchar()) != ' ' && c != '\n') {
			inputStr[len++] = c;
		}
		inputStr[len++] = '\0';
		pieces[i] = inputStr;
		inputStr += len;
	}

	int* next = (int*)calloc(n + 1, sizeof(int));
	int* tail = (int*)malloc((n + 1) * sizeof(int));
	int* isAttached = (int*)calloc(n + 1, sizeof(int));

	for (int i = 1; i <= n; i++) tail[i] = i;

	for (int i = 1; i < n; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);
		next[tail[b]] = a;
		tail[b] = tail[a];
		isAttached[a] = 1;
	}

	int root = 1;
	while (isAttached[root]) root++;
	free(isAttached);

	int cur = root;
	while (cur != 0) {
		printf("%s", pieces[cur]);
		cur = next[cur];
	}

	free(next);
	free(input);
	free(pieces);

	return 0;
}