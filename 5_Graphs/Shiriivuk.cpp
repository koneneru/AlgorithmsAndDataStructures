#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "5_Graphs.h"

typedef struct {
    char str[51];
} Syllable;

int syl_cmp(const void* a, const void* b) {
    return strcmp(((Syllable*)a)->str, ((Syllable*)b)->str);
}

int Shiriivuk() {
    char** words = (char**)malloc(50 * sizeof(char*));
    if (!words) return -1;

    int n;
    scanf_s("%d", &n);

    char letters[26] = { 0 };
    for (int i = 0; i < n; i++) {
        words[i] = (char*)malloc(51 * sizeof(char));
        if (!words[i]) return -1;

        scanf_s("%50s", words[i], 51);
        for (int j = 0; words[i][j]; j++) {
            letters[words[i][j] - 'a'] = 1;
        }
    }

    char alphabet[26] = { 0 };
    int alpha_size = 0;
    for (int i = 0; i < 26; i++) {
        if (letters[i]) {
            alphabet[alpha_size++] = 'a' + i;
        }
    }

    char next_in_syllable[256];
    char prev_in_syllable[256];
    memset(next_in_syllable, 0, sizeof(next_in_syllable));
    memset(prev_in_syllable, 0, sizeof(prev_in_syllable));

    for (int i = 0; i < alpha_size; i++) {
        char a = alphabet[i];
        char candidate_b = -1;
        bool always_followed_by_same = true;
        bool found_at_least_once = false;

        for (int j = 0; j < n; j++) {
            char* p = words[j];
            while ((p = strchr(p, a)) != NULL) {
                char b = p[1];
                if (!found_at_least_once) {
                    candidate_b = b;
                    found_at_least_once = true;
                }
                else if (b != candidate_b) {
                    always_followed_by_same = false;
                    break;
                }
                p++;
            }
            if (!always_followed_by_same) break;
        }

        if (always_followed_by_same && candidate_b != 0 && candidate_b != -1) {
            bool always_preceded_by_a = true;
            for (int j = 0; j < n; j++) {
                for (int k = 0; words[j][k]; k++) {
                    if (words[j][k] == candidate_b) {
                        if (k == 0 || words[j][k - 1] != a) {
                            always_preceded_by_a = false;
                            break;
                        }
                    }
                }
                if (!always_preceded_by_a) break;
            }

            if (always_preceded_by_a) {
                next_in_syllable[(unsigned char)a] = candidate_b;
                prev_in_syllable[(unsigned char)candidate_b] = a;
            }
        }
    }

    Syllable ans[256];
    int cnt = 0;
    bool visited[256] = { false };

    for (int i = 0; i < alpha_size; i++) {
        char curr = alphabet[i];
        if (!visited[curr] && prev_in_syllable[curr] == 0) {
            int len = 0;
            while (curr != 0) {
                ans[cnt].str[len++] = (char)curr;
                visited[curr] = true;
                curr = next_in_syllable[curr];
            }
            ans[cnt].str[len] = '\0';
            cnt++;
        }
    }

    qsort(ans, cnt, sizeof(Syllable), syl_cmp);

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", ans[i].str);
    }

    for (int i = 0; i < n; i++) free(words[i]);
    free(words);

    return 0;
}