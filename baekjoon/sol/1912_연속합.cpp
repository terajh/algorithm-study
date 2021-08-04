#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <queue>
#include <vector>

#define rep(i, n) for (i = 1; i <= n; i++)

typedef long long LL;
using namespace std;

LL arr[100001];
LL dp[100001];

int main()
{
    // dp[]
    int n, k, i;
    vector<pair<int, int>> q;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    dp[0] = arr[0];
    LL _max = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        _max = max(dp[i], _max);
    }
    printf("%d\n", _max);
}