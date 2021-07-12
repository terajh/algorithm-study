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

const LL INF = 1000000000;

LL dp[101][101];
LL getCounts(int a, int b)
{
    if (a == 0 || b == 0)
        return 1;
    if (dp[a][b] != 0)
        return dp[a][b];
    dp[a][b] = getCounts(a - 1, b) + getCounts(a, b - 1);
    if (dp[a][b] > INF)
        dp[a][b] = INF;
    return dp[a][b];
}
int main()
{
    int n, m;
    LL k;
    cin >> n >> m >> k;

    string answer;
    int countA = n, countZ = m;
    if (getCounts(n, m) < k)
        cout << -1;
    else
    {
        for (int i = 0; i < n + m; i++)
        {
            if (countA > 0)
            {
                LL tp = getCounts(countA - 1, countZ);
                if (tp < k)
                {
                    answer.push_back('z');
                    k -= tp;
                    countZ--;
                }
                else
                {
                    answer.push_back('a');
                    countA--;
                }
            }
            else
            {
                answer.push_back('z');
            }
        }
        cout << answer;
    }
}