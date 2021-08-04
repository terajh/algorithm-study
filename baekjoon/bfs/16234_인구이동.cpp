

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <string.h>
#include <map>;
#include <tuple>

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
int n, l, r;
int arr[51][51];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
map<int, int> m;
int check[51][51];

void bfs(int x, int y, int color)
{
    queue<pii> q;
    deque<pii> group;
    int sum = 0;
    int cx, cy, tx, ty;
    q.push({x, y});
    sum += arr[x][y];
    group.push_back({x, y});
    while (!q.empty())
    {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            tx = cx + dx[i];
            ty = cy + dy[i];
            if (tx < 1 || ty < 1 || tx > n || ty > n)
                continue;
            if (abs(arr[tx][ty] - arr[cx][cy]) < l || abs(arr[tx][ty] - arr[cx][cy]) > r)
                continue;
            if (check[tx][ty] != 0)
                continue;

            check[tx][ty] = color;
            q.push({tx, ty});
            group.push_back({tx, ty});
            sum += arr[tx][ty];
        }
    }
    m[color] = sum / group.size();
}
int main()
{
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    //	1. bfs 로 한칸씩 확인하면서 하루마다 인구이동
    //	2. 인구 이동 하며 며칠이 지났는지 체크하고 q 가 비게 되었을 때
    //		해당 날수를 답으로 체킹

    bool conti;
    int res = 0, color;
    while (1)
    {
        conti = false;
        color = 1;
        memset(check, 0, sizeof(check));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (check[i][j] == 0)
                {
                    check[i][j] = color;
                    bfs(i, j, color++);
                }
            }
        }
        if (color > n * n)
            break;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                arr[i][j] = m[check[i][j]];
            }
        }
        res += 1;
    }
    printf("%d\n", res);

    return 0;
}