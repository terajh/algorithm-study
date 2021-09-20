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
    int a;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &a);
        pq.push({ a, i+1 });
    }
    printf("%d\n%d", pq.top().first, pq.top().second);
    return 0;
}