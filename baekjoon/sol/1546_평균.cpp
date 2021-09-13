#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

#define MAX_INT 1000000000
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;
double arr[1001];
int main() {
    int n,a ;
    scanf("%d", &n);
    double res = 0;
    double maxn = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
        maxn = max(maxn, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = (arr[i] / maxn) * 100;
    }
    for (int i = 0; i < n; i++) {
        res += arr[i];
    }
    printf("%lf", res / n);
    return 0;
}