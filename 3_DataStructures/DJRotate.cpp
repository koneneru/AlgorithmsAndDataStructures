#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int type;
    int x;
} Op;

int mod(int a, int b) {
    int r = a % b;
    return r < 0 ? r + b : r;
}

typedef struct Node {
    int val;
    unsigned int prio;
    int size;
    struct Node* l, * r;
} Node;

typedef struct {
    Node* pool;
    int poolPtr;
    Node* root;
} Treap;

Treap* treap_create(int cap) {
    Treap* t = (Treap*)malloc(sizeof(Treap));
    if (!t) {
        fprintf(stderr, "memory allocation failed");
        exit(1);
    }

    t->poolPtr = 0;
    t->root = NULL;
    t->pool = (Node*)malloc(cap * sizeof(Node));
    if (!t->pool) {
        fprintf(stderr, "memory allocation failed");
        exit(1);
    }

    return t;
}

void treap_destroy(Treap** tPtr) {
    if (!tPtr || !*tPtr) return;

    Treap* t = *tPtr;
    free(t->pool);
    free(t);

    *tPtr = NULL;
}

int getSize(Node* n) {
    return n ? n->size : 0;
}

void update(Node* n) {
    if (!n) return;
    n->size = 1 + getSize(n->l) + getSize(n->r);
}

Node* addNode(Treap* t, int v) {
    Node* n = &t->pool[t->poolPtr++];
    if (!n) {
        fprintf(stderr, "memory allocation failed");
        exit(1);
    }

    n->val = v;
    n->prio = (unsigned int)((rand() << 15) ^ rand());
    n->size = 1;
    n->l = n->r = NULL;

    return n;
}

void split(Node* t, int k, Node** l, Node** r) {
    if (!t) {
        *l = *r = NULL;
        return;
    }

    int cur = getSize(t->l);
    if (cur < k) {
        split(t->r, k - cur - 1, &t->r, r);
        *l = t;
    }
    else {
        split(t->l, k, l, &t->l);
        *r = t;
    }
    update(t);
}

Node* merge(Node* l, Node* r) {
    if (!l || !r) return l ? l : r;

    if (l->prio < r->prio) {
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
    else {
        l->r = merge(l->r, r);
        update(l);
        return l;
    }
}

Node* rotate(Node* node, int shift, int len) {
    if (len <= 1) return node;
    int s = ((-shift % len) + len) % len;
    if (s == 0) return node;

    Node* l, * r;
    split(node, len - s, &l, &r);
    return merge(r, l);
}

void printTreap(Node* t) {
    if (!t) return;
    printTreap(t->l);
    printf("%d ", t->val);
    printTreap(t->r);
}

void solveShift(Op* ops, int opCnt, int n, int k) {
    int* shift = (int*)malloc(k * sizeof(int));
    if (!shift) {
        fprintf(stderr, "memory allocation failed");
        exit(1);
    }

    for (int i = 0; i < k; i++) {
        int cur = i;

        for (int j = 0; j < opCnt; j++) {
            if (ops[j].type == 1) {
                int sec = (cur / k) * k;
                cur = sec + mod(cur + ops[j].x, k);
            }
            else {
                cur = mod(cur + ops[j].x, n);
            }
        }
        shift[i] = cur - i;
    }

    int* a = (int*)malloc(n * sizeof(int));
    int* z = (int*)malloc(n * sizeof(int));
    if (!(a && z)) {
        fprintf(stderr, "memory allocation failed");
        exit(1);
    }

    for (int i = 0; i < n; i++) scanf_s("%d", &z[i]);

    for (int i = 0; i < n; i++) {
        a[i] = z[mod(i + shift[i % k], n)];
    }

    for (int i = 0; i < n; i++) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar('\n');
}

void solveTreap(Op* ops, int opCnt, int n, int k) {
    Treap* treap = treap_create(n);

    for (int i = 0; i < n; i++) {
        int z;
        scanf_s("%d", &z);
        treap->root = merge(treap->root, addNode(treap, z));
    }
    Node** sections = (Node**)malloc(n * sizeof(Node*));
    if (!sections) {
        fprintf(stderr, "memory allocation failed");
        exit(1);
    }

    for (int i = opCnt - 1; 0 <= i; i--) {
        if (ops[i].type == 1) {
            Node* cur = treap->root;
            int secNum = n / k;
            for (int j = 0; j < secNum; j++) {
                Node* sec, * next;
                split(cur, k, &sec, &next);
                sections[j] = rotate(sec, ops[i].x, k);
                cur = next;
            }
            treap->root = NULL;
            for (int j = 0; j < secNum; j++) {
                treap->root = merge(treap->root, sections[j]);
            }
        }
        else {
            treap->root = rotate(treap->root, ops[i].x, n);
        }
    }

    printTreap(treap->root);
    putchar('\n');

    treap_destroy(&treap);
    free(sections);
}

int DJRotate() {
    int n, k, q;
    scanf_s("%d %d %d", &n, &k, &q);

    Op* ops = (Op*)malloc(q * sizeof(Op));
    if (!ops) return 1;

    int opCnt = 0;
    for (int i = 0; i < q; i++) {
        int a, x;
        scanf_s("%d %d", &a, &x);

        if (k == 1 && a == 1) continue;
        if (k == n && a == 1) a = 2;

        if (0 < opCnt && a == ops[opCnt - 1].type) {
            long long totalX = (long long)ops[opCnt - 1].x + x;
            ops[opCnt - 1].x = (int)(totalX % (a == 1 ? k : n));
        }
        else {
            ops[opCnt].type = a;
            ops[opCnt].x = x % (a == 1 ? k : n);
            opCnt++;
        }
    }

    if (k < 1500) solveShift(ops, opCnt, n, k);
    else solveTreap(ops, opCnt, n, k);

    free(ops);

    return 0;
}