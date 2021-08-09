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

int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void input(int &a) { scanf("%d", &a); }
void output(int a) { printf("%d\n", a); }

struct tomato
{
    int x, y, z, t;
};

int main()
{
    int m, n, h, i, j, a, b;
    input(m);

    rep(i, m)
    {
        vector<pair<int, int>> pon;
        input(n);
        rep(j, 2)
        {
            input(a), input(b);
            pon.push_back({a, b});
        }

        int check[301][301] = {
            0,
        };
        int _max = 0;

        queue<tuple<int, int, int>> q;
        q.push({pon[0].first, pon[0].second, 1});
        check[pon[0].first][pon[0].second] = 1;
        while (!q.empty())
        {
            tuple<int, int, int> top = q.front();
            q.pop();
            if (get<0>(top) == pon[1].first && get<1>(top) == pon[1].second)
            {
                _max = max(_max, get<2>(top) - 1);
            }
            int tx, ty, tt = get<2>(top);
            for (int i = 0; i < 8; i++)
            {
                tx = get<0>(top) + dx[i];
                ty = get<1>(top) + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n)
                    continue;
                if (check[tx][ty] != 0 && check[tx][ty] <= tt + 1)
                    continue;
                if (check[tx][ty] == 0)
                {
                    check[tx][ty] = tt + 1;
                    q.push({tx, ty, tt + 1});
                }
            }
        }
        output(_max);
    }
    return 0;
}