

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <string.h>
#include <tuple>

using namespace std;
typedef long long LL;
typedef tuple<int, int, int> tii;
typedef pair<int, int> pii;

int arr[101][101];
int colors[101][101];
int check[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<tii> q;
int n;
vector<vector<int>> v(100);
void bfs(int x, int y, int color)
{
    q.push({x, y, color});

    tii tp;
    int tx, ty, tc;
    while (!q.empty())
    {
        tp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            tx = get<0>(tp) + dx[i];
            ty = get<1>(tp) + dy[i];
            if (tx <= 0 || ty <= 0 || tx > n || ty > n)
                continue;
            if (check[tx][ty] != 0 || arr[tx][ty] != 1)
                continue;

            colors[tx][ty] = get<2>(tp);
            check[tx][ty] = 1;
            q.push({tx, ty, get<2>(tp)});
        }
    }
}
int _min = 10000;
int bfs_bridge(int color)
{
    queue<pii> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (colors[i][j] == color)
            {
                check[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    int tx, ty, qx, qy;
    int res = 0;
    while (!q.empty())
    {
        int _size = q.size();
        for (int k = 0; k < _size; k++)
        {
            qx = q.front().first;
            qy = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                tx = qx + dx[i];
                ty = qy + dy[i];
                if (tx <= 0 || ty <= 0 || tx > n || ty > n)
                    continue;

                if (arr[tx][ty] == 1 && colors[tx][ty] != color)
                {
                    // 다른 곳에 도착
                    check[tx][ty] = 1;
                    // printf("%d %d %d\n", tx, ty, res);
                    return res;
                }
                else if (check[tx][ty] == 0 && arr[tx][ty] == 0)
                {
                    check[tx][ty] = 1;
                    q.push({tx, ty});
                }
            }
        }
        res += 1;
    }
}
int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (colors[i][j] == 0 && arr[i][j] == 1 && check[i][j] == 0)
            {
                colors[i][j] = cnt;
                check[i][j] = 1;
                bfs(i, j, cnt++);
                while (!q.empty())
                    q.pop();
            }
        }
    }

    for (int i = 1; i < cnt; i++)
    {
        memset(check, 0, sizeof(check));
        // printf("color : %d\n", i);
        _min = min(_min, bfs_bridge(i));
        while (!q.empty())
            q.pop();
    }
    printf("%d\n", _min);

    return 0;
}