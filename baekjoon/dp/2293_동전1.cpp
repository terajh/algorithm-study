#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <queue>
#include <vector>

#define rep(i, n) for (i = 1; i <= n; i++)

using namespace std;
typedef long long LL;
int arr[100001];
LL dp[100001];

void input(int &a)
{
    scanf("%d", &a);
}
void output(int a)
{
    printf("%d\n", a);
}
int main()
{
    int n, k, i;
    input(n);
    input(k);

    rep(i, n)
        input(arr[i]);
    sort(arr, arr + n);

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > k)
            continue;
        dp[arr[i]] += 1;
        for (int j = arr[i] + 1; j <= k; j++)
            dp[j] += dp[j - arr[i]];
    }

    printf("%lld\n", dp[k]);
    return 0;
}