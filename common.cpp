#include "common.h"

int min(int a, int b) {
    return a < b ? a : b;
}

int minOf3(int a, int b, int c) {
    return min(min(a, b), min(b, c));
}

int max(int a, int b) {
    return a < b ? b : a;
}