#include <stdio.h>
#include "../common.h"
#include "4_DynamicProgramming.h"

int Hike() {
	int ctnL = 0;
	int ctnR = 1;

	char c, pc = 'L';
	while ((c = getchar()) != '\n') {
		if (c == 'B') {
			ctnL++;
			ctnR++;
			continue;
		}

		if (c == 'L') ctnL = min(ctnL, ctnR) + 1;
		else ctnR = min(ctnL, ctnR) + 1;
	}

	printf("%d", ctnR);

	return 0;
}