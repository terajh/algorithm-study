#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <stack>

#define MAX_INT 1000000000
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

LL arr[200001];
int main() {
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
    }
    stack<LL> s;
    s.push(0);
    LL res = 0;
    for (LL i = 1; i <= n+1; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            LL a = s.top();
            s.pop();
            res = max(res, arr[a] * (i - s.top() - 1));
        }
        s.push(i);
    }
    printf("%lld", res);


}