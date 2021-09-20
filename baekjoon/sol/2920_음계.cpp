#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>

#define MAX_INT 1000000000
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

int main() {
    priority_queue<pii> pq;
    int cur = 0, prev = 0;
    int mode = 0;
    for (int i = 0; i < 8; i++) {
        prev = cur;
        scanf("%d", &cur);

        if (i == 0) continue;
        if (i == 1) {
            if (prev < cur) mode = 1;
            else if (prev > cur) mode = 2;
        }
        else {
            if (prev < cur && mode == 1) continue;
            else if (prev > cur && mode == 2) continue;
            else {
                printf("mixed");
                return 0;
            }
        }
    }
    if (mode == 1) printf("ascending");
    else if (mode == 2) printf("descending");
    return 0;
}