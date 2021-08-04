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

int dp[501][501];
int arr[501][501];

int main()
{
    // dp[]
    int n, k, i;
    vector<pair<int, int>> q;

    scanf("%d", &n);
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    dp[0][0] = arr[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j] + arr[i][j]);
            }
        }
    }

    int _max = 0;
    for (int i = 0; i < n; i++)
    {
        _max = max(dp[n - 1][i], _max);
    }
    printf("%d\n", _max);
}