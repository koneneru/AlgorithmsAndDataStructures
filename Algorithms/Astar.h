#pragma once
#define ASTAR_H

#include "../DataStructures/GenericStack.h"

typedef struct {
	int x, y;
	int g, f;
	int parentX, parentY;
	char closed;
	char available;
} Node;

TStack Astar(Node** grid, int n, int sx, int sy, int tx, int ty);