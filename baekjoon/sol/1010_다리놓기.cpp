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

int nCr(int n, int r)
{
    if (r == 0)
        return 1;
    if (n < r)
        return 0;

    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}
int main()
{
    int n, m, k;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m >> k;
        int dp[50][50];

        dp[0][0] = 1;
        for (int i = 1; i <= k; i++)
        {
            dp[i][0] = 1;
            dp[i][i] = 1;
        }

        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i - 1 < j)
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]);
            }
        }
        printf("%d\n", dp[k][m]);
    }
}