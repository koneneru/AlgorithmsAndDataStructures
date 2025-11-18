#include <stdio.h>

int AliceBobAndBeautifulLines() {
	const int mod = 1000000007;

	int n;
	scanf_s("%d", &n);

	long long a1 = 1, a2 = 0, a3 = 0;
	long long b1 = 1, b2 = 0;

	for (int i = 1; i < n; i++) {
		long long na1, na2, na3, nb1, nb2;

		na1 = (b1 + b2) % mod;
		na2 = a1;
		na3 = a2;

		nb1 = (a1 + a2 + a3) % mod;
		nb2 = b1;

		a1 = na1;
		a2 = na2;
		a3 = na3;
		b1 = nb1;
		b2 = nb2;
	}

	printf("%lld", (a1 + a2 + a3 + b1 + b2) % mod);

	return 0;
}