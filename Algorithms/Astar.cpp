#include <stdlib.h>
#include "../DataStructures/BinHeap.h"
#include "../DataStructures/Pair.h"
#include "../DataStructures/GenericStack.h"
#include "Astar.h"

int calculateH(int x, int y, int tx, int ty) {
	return abs(x - tx) + abs(y - ty);
}

TStack Astar(Node** grid, int n, int sx, int sy, int tx, int ty) {
	TStack trace = {};
	stack_init(&trace, sizeof(IntPair));
	BinHeap* openSet = binHeap_create(n * n);

	Node* startNode = &grid[sx][sy];
	grid[sx][sy].g = 0;
	grid[sx][sy].f = calculateH(sx, sy, tx, ty);
	binHeap_push(openSet, { sx, sy, grid[sx][sy].f });

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };
	HeapItem top;
	while (binHeap_pop(openSet, &top)) {
		Node* current = &grid[top.x][top.y];

		if (current->f < top.f) continue;

		if (current->x == tx && current->y == ty) {
			int curX = tx;
			int curY = ty;

			while (!(curX == -1 && curY == -1)) {
				IntPair pair = { curX, curY };
				stack_push(&trace, &pair);

				int nextX = grid[curX][curY].parentX;
				int nextY = grid[curX][curY].parentY;

				curX = nextX;
				curY = nextY;
			}

			break;
		}

		current->closed = 1;

		for (int i = 0; i < 4;i++) {
			int nx = current->x + dx[i];
			int ny = current->y + dy[i];

			if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
			Node* neighbor = &grid[nx][ny];

			if (!neighbor->available || neighbor->closed) continue;

			int tentative_g = current->g + 1;

			if (tentative_g < neighbor->g) {
				neighbor->parentX = current->x;
				neighbor->parentY = current->y;
				neighbor->g = tentative_g;
				neighbor->f = tentative_g + calculateH(nx, ny, tx, ty);

				HeapItem nextItem = { nx, ny, neighbor->f };
				binHeap_push(openSet, nextItem);
			}
		}
	}

	binHeap_destroy(openSet);
	return trace;
}