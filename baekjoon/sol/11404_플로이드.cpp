#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#define INF 987654321;
using namespace std;

typedef long long LL;

int arr[101][101];
int dp[101][101];

int main()
{
    int n, m, to, from, weight;
    scanf("%d %d", &n, &m);

    // 배열 초기화
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &from, &to, &weight);
        if (arr[from][to] > weight)
            arr[from][to] = weight;
    }

    // 거쳐가는 노드

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || arr[i][j] == 987654321)
            {
                printf("0 ");
            }
            else
                printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}