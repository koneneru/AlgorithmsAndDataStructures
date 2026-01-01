#include <stdio.h>

typedef struct {
	int limit;
	int n;
	char spells[38];
	int adj[36][36];
	int visited[36];
	int maxDist[36];
	int nextV[36];
	int isAvailable[36];
	int degree[36];

	int castLen;
	char castQueue[1001];
} SpellstormSolver;

int dfs(int u, SpellstormSolver* s) {
	if (s->visited[u] == 1) return -1;
	if (s->visited[u] == 2) return s->maxDist[u];

	s->visited[u] = 1;
	int maxLen = 0;
	s->nextV[u] = -1;

	for (int v = 0; v < s->n; v++) {
		if (!s->adj[u][v]) continue;

		int res = dfs(v, s);
		if (res == -1) return -1;

		if (maxLen < res) {
			maxLen = res;
			s->nextV[u] = v;
		}
	}

	s->visited[u] = 2;
	s->maxDist[u] = maxLen + 1;
	return s->maxDist[u];
}

int get_id(char c, int n, char* spells) {
	for (int i = 0; i < n; i++) {
		if (spells[i] == c) return i;
	}
	return -1;
}

int has_cycle(int u, SpellstormSolver* s) {
	s->visited[u] = 1;
	for (int v = 0; v < s->n; v++) {
		if (s->adj[u][v] && (s->visited[v] == 1 || (s->visited[v] == 0 && has_cycle(v, s)))) return 1;
	}

	s->visited[u] = 2;
	return 0;
}

void cast(int u, int mode, SpellstormSolver* s) {
	for (int v = 0; v < s->n; v++) {
		if (s->adj[u][v] && s->isAvailable[v]) cast(v, mode, s);
	}

	if (s->isAvailable[u]) {
		if (mode) putchar(s->spells[u]);

		s->isAvailable[u] = 0;
		s->castLen++;
		if (s->limit < s->castLen) return;

		for (int v = 0; v < s->n; v++) {
			if (s->adj[u][v]) s->isAvailable[v] = 1;
		}

		for (int v = 0; v < s->n; v++) {
			if (s->adj[u][v] && s->isAvailable[v]) cast(v, mode, s);
		}
	}
}

int Spellstorm()
{
	SpellstormSolver s = { 1000 };
	int m;

	scanf_s("%d %d\n", &s.n, &m);
	fgets(s.spells, sizeof(s.spells), stdin);

	for (int i = 0; i < m; i++) {
		char w[12];
		fgets(w, sizeof(w), stdin);
		int u = get_id(w[0], s.n, s.spells);
		int v = get_id(w[9], s.n, s.spells);

		if (u != -1 && v != -1) {
			s.adj[u][v] = 1;
		}
	}

	for (int i = -0; i < s.n; i++) {
		if (!s.visited[i] && has_cycle(i, &s)) {
			puts("spellstorm");
			return 0;
		}
	}

	for (int i = 0; i < s.n; i++) s.isAvailable[i] = 1;
	for (int i = 0; i < s.n; i++) {
		if (s.degree[i] == 0) cast(i, 0, &s);
	}

	if (s.limit < s.castLen) {
		puts("spellstorm");
	}
	else {
		s.castLen = 0;
		for (int i = 0; i < s.n; i++) s.isAvailable[i] = 1;
		for (int i = 0; i < s.n; i++) {
			if (s.degree[i] == 0) cast(i, 1, &s);
		}
		putchar('\n');
	}

	return 0;
}