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

int arr[100001];
int dp[100001][3];

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
    dp[0][0] = arr[0]; // 이전꺼 포함 X
    dp[0][1] = arr[0]; // 이전꺼 포함
    dp[1][0] = arr[1];
    dp[1][1] = arr[0] + arr[1];

    for (int i = 2; i <= n; i++)
    {
        // 이전꺼 포함 X
        dp[i][0] = max(dp[i - 2][0] + arr[i], dp[i - 2][1] + arr[i]);

        // 이전꺼 포함
        dp[i][1] = max(dp[i - 1][0] + arr[i], dp[i - 1][1]);
    }

    printf("%d\n", max(dp[n][0], dp[n][1]));
}