#include <stdio.h>
#include <limits.h>
#include "5_Graphs.h"

int FlightsInTime()
{
	typedef struct {
		int from, to;
		long long td, ta;
	} Flight;

	int n, a, b, k;
	scanf_s("%d\n%d %d\n%d", &n, &a, &b, &k);

	Flight flights[1000] = {};
	for (int i = 0; i < k; i++) {
		Flight* f = &flights[i];
		scanf_s("%d%lld%d%lld", &f->from, &f->td, &f->to, &f->ta);
	}

	long long t_min[1001] = { 0L };
	for (int i = 1; i < n; i++) {
		t_min[i] = LLONG_MAX;
	}
	t_min[a] = 0L;

	int changed = 1;
	while (changed) {
		changed = 0;
		for (int i = 0; i < k; i++) {
			int u = flights[i].from;
			int v = flights[i].to;
			long long td = flights[i].td;
			long long ta = flights[i].ta;

			if (t_min[u] != LLONG_MAX && t_min[u] <= td) {
				if (ta < t_min[v]) {
					t_min[v] = ta;
					changed = 1;
				}
			}
		}
	}

	printf("%lld\n", t_min[b]);

	return 0;
}