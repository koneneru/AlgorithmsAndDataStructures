#include <stdio.h>
#include "5_Graphs.h"

int CellRemoval()
{
	char sheet[102][102] = { 0 };
	int m, n;
	scanf_s("%d %d", &m, &n);

	for (int i = 1; i <= m; i++) {
		scanf_s("%s", &sheet[i][1], 101);
	}

	int visited[102][102] = { 0 };
	int di[4] = { -1, 1, 0, 0 };
	int dj[4] = { 0, 0, -1, 1 };
	int qi[10000] = { 0 };
	int qj[10000] = { 0 };
	int qh = 0;
	int qt = 0;
	int chunks = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && sheet[i][j] == '#') {
				chunks++;
				qi[qt] = i;
				qj[qt++] = j;
				visited[i][j] = 1;

				while (qh < qt) {
					int x = qi[qh];
					int y = qj[qh++];
					for (int k = 0; k < 4; k++) {
						int dx = x + di[k];
						int dy = y + dj[k];
						if (!visited[dx][dy] && sheet[dx][dy] == '#') {
							visited[dx][dy] = 1;
							qi[qt] = dx;
							qj[qt++] = dy;
						}
					}
				}
			}
		}
	}

	printf("%d", chunks);

	return 0;
}
