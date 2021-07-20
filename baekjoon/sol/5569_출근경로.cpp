#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>
#include <math.h>
#include <map>

#define R 0
#define U 1
using namespace std;
typedef long long LL;

int m, k;
int dp[101][101][2][2];
int main()
{
    int row, col;
    cin >> col >> row;
    for (int i = 2; i <= col; i++)
    {
        dp[1][i][R][0] = 1;
    }
    for (int i = 2; i <= row; i++)
    {
        dp[i][1][U][0] = 1;
    }

    for (int i = 2; i <= row; i++)
    {
        for (int j = 2; j <= col; j++)
        {
            dp[i][j][R][0] = (dp[i][j - 1][R][0] + dp[i][j - 1][R][1]) % 100000;
            dp[i][j][U][0] = (dp[i - 1][j][U][0] + dp[i - 1][j][U][1]) % 100000;
            dp[i][j][R][1] = dp[i][j - 1][U][0] % 100000; // 방향 전환 불가
            dp[i][j][U][1] = dp[i - 1][j][R][0] % 100000; // 방향전환 불가
        }
    }

    cout << (dp[row][col][R][0] + dp[row][col][R][1] + dp[row][col][U][0] + dp[row][col][U][1]) % 100000;
}