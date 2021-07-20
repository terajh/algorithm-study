#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;
typedef long long LL;

LL dp[1001][1001];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - 1 < j)
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
        }
    }
    printf("%lld", dp[n][k] % 10007);
}