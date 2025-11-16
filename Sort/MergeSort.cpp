#include "Sort.h"

void mergeSort(int* a, int* b, int l, int r) {
	if (r <= l) return;

	int m = (l + r) / 2;
	mergeSort(a, b, l, m);
	mergeSort(a, b, m + 1, r);

	int k = l;
	for (int i = l, j = m + 1; i <= m || j <= r;) {
		if (r < j || (i <= m && a[i] < a[j])) {
			b[k] = a[i++];
		}
		else {
			b[k] = a[j++];
		}
		k++;
	}

	for (int i = l; i <= r; i++) {
		a[i] = b[i];
	}
}