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
LL dp[100001][2];

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
    rep(i, n)
    {
        input(arr[i]);
    }

    dp[1][0] = arr[1];
    dp[1][1] = arr[1];
    dp[2][0] = dp[1][1] + arr[2];
    dp[2][1] = arr[2];
    for (int i = 3; i <= n; i++)
    {
        // 이전꺼 연속으로 밟은 경우
        dp[i][0] = dp[i - 1][1] + arr[i];
        // 이전꺼 뺴고 밟은 경우
        dp[i][1] = max(dp[i - 2][1] + arr[i], dp[i - 2][0] + arr[i]);
    }
    printf("%lld\n", max(dp[n][0], dp[n][1]));
}