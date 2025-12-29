#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "../Algorithms/Astar.h"
#include "../DataStructures/BinHeap.h"
#include "../DataStructures/Pair.h"
#include "../DataStructures/GenericStack.h"

int Lines()
{
	char A[41][41] = { 0 };

	int n;
	scanf_s("%d", &n);

	Node** grid = (Node**)malloc(n * sizeof(Node*));
	if (!grid) return 1;
	for (int i = 0; i < n; i++) {
		grid[i] = (Node*)malloc(n * sizeof(Node));
		if (!grid[i]) return 1;

		scanf_s("%s", &A[i], 41);
	}

	int sx = 0, sy = 0;
	int tx = 0, ty = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			grid[i][j] = { i, j, INT_MAX, INT_MAX, -1, -1, 0, 1 };
			switch (A[i][j]) {
			case '@':
				sx = i;
				sy = j;
				grid[i][j].parentX = -1;
				grid[i][j].parentY = -1;
				break;
			case 'X':
				tx = i;
				ty = j;
				break;
			case 'O':
				grid[i][j].available = 0;
				break;
			}
		}
	}

	TStack trace = Astar(grid, n, sx, sy, tx, ty);

	int possible = trace.top != -1;

	puts(possible ? "Y" : "N");

	stack_pop(&trace, NULL);
	while (trace.top != -1) {
		IntPair step;
		stack_pop(&trace, &step);
		A[step.x][step.y] = '+';
	}

	if (possible)
		for (int i = 0; i < n; i++) puts(A[i]);

	stack_free(&trace);

	for (int i = 0; i < n; i++) {
		free(grid[i]);
	}
	free(grid);

	return 0;
}