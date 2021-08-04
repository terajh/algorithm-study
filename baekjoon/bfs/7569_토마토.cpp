#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <queue>
#include <vector>
#include <tuple>

#define rep(i, n) for (i = 1; i <= n; i++)

using namespace std;
int arr[101][101][101];
int check[101][101][101];

int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

void input(int &a) { scanf("%d", &a); }
void output(int a) { printf("%d\n", a); }
struct tomato
{
    int x, y, z, t;
};
int main()
{
    int m, n, h, i;
    input(m), input(n), input(h);

    vector<tuple<int, int, int>> didMato;
    for (int k = 1; k <= h; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                input(arr[i][j][k]);
                if (arr[i][j][k] == 1)
                    didMato.push_back({i, j, k});
            }
        }
    }

    queue<tomato> q;
    for (auto tu : didMato)
    {
        tomato t;
        t.x = get<0>(tu);
        t.y = get<1>(tu);
        t.z = get<2>(tu);
        t.t = 0;
        q.push(t);
    }

    while (!q.empty())
    {
        tomato tp = q.front();
        q.pop();

        int tx, ty, tz, tt;
        for (int i = 0; i < 6; i++)
        {
            tx = tp.x + dx[i];
            ty = tp.y + dy[i];
            tz = tp.z + dz[i];
            tt = tp.t + 1;
            if (tx < 1 || tx > n || ty < 1 || ty > m || tz < 1 || tz > h)
                continue;
            if (arr[tx][ty][tz] == 1 || arr[tx][ty][tz] == -1)
                continue;
            if (check[tx][ty][tz] != 0 && check[tx][ty][tz] < tt)
                continue;

            if (check[tx][ty][tz] == 0)
            {
                check[tx][ty][tz] = tt;
                tomato _tp;
                _tp.x = tx, _tp.y = ty, _tp.z = tz;
                _tp.t = tt;
                q.push(_tp);
            }
            else if (check[tx][ty][tz] != 0)
            {
                if (check[tx][ty][tz] <= tt)
                    continue;
                else
                {
                    check[tx][ty][tz] = tt;
                    tomato _tp;
                    _tp.x = tx, _tp.y = ty, _tp.z = tz;
                    _tp.t = tt;
                    q.push(_tp);
                }
            }
        }
    }

    int _max = 0;
    bool isok = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= h; k++)
            {
                if (arr[i][j][k] == 0 && check[i][j][k] == 0)
                {
                    // printf("%d %d %d\n", i, j, k);
                    isok = true;
                    break;
                }
                else if (arr[i][j][k] == 0)
                {
                    _max = max(_max, check[i][j][k]);
                }
            }
        }
    }

    if (isok == false)
        printf("%d\n", _max);
    else
        printf("-1\n");
    return 0;
}