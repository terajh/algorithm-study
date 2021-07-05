#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>

using namespace std;

char arr[51][51];
int check[51][51];
int bfs[51][51];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct node
{
    int x;
    int y;
    int time;
};
int main()
{

    int r, c;
    cin >> r >> c;

    queue<node> q;
    int tox, toy;
    int sx, sy;
    vector<pair<int, int>> w;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf(" %1c", &arr[i][j]);
            if (arr[i][j] == 'S')
            {
                sx = i;
                sy = j;
                check[i][j] = -1;
            }
            else if (arr[i][j] == 'D')
            {
                tox = i;
                toy = j;
                check[i][j] = -1;
            }
            else if (arr[i][j] == '*')
            {
                w.push_back({i, j});
            }
            else if (arr[i][j] == 'X')
            {
                check[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < w.size(); k++)
    {
        node n;
        n.x = w[k].first;
        n.y = w[k].second;
        n.time = 0;
        q.push(n);
    }

    while (!q.empty())
    {
        node t = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int tx = t.x + dx[i];
            int ty = t.y + dy[i];
            if (tx >= r || tx < 0 || ty >= c || ty < 0)
                continue;

            if (check[tx][ty] != -1)
            {
                if (check[tx][ty] == 0 && arr[tx][ty] != '*')
                {
                    node temp;
                    temp.x = tx;
                    temp.y = ty;
                    temp.time = t.time + 1;
                    q.push(temp);
                    check[tx][ty] = t.time + 1;
                }
                else if (t.time + 1 < check[tx][ty])
                {
                    check[tx][ty] = t.time + 1;
                    node temp;
                    temp.x = tx;
                    temp.y = ty;
                    q.push(temp);
                    temp.time = t.time + 1;
                }
            }
        }
    }

    node go;
    go.x = sx;
    go.y = sy;
    go.time = 0;
    bfs[sx][sy] = -1;
    q.push(go);
    int _min = 100000000;

    while (!q.empty())
    {
        node t = q.front();
        q.pop();
        // printf("%d %d %d\n", t.x, t.y, t.time);
        if (t.x == tox && t.y == toy)
        {
            _min = (_min < t.time) ? _min : t.time;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = t.x + dx[i];
            int ty = t.y + dy[i];
            if (tx >= r || tx < 0 || ty >= c || ty < 0)
                continue;
            if (bfs[tx][ty] != -1)
            {
                if (check[tx][ty] != -1 && check[tx][ty] != 0 && check[tx][ty] <= t.time + 1)
                    continue;
                node temp;
                temp.x = tx;
                temp.y = ty;
                temp.time = t.time + 1;
                if (bfs[tx][ty] == 0 && arr[tx][ty] != 'X')
                {
                    bfs[tx][ty] = t.time + 1;
                    q.push(temp);
                }
                else if (bfs[tx][ty] > t.time + 1 && arr[tx][ty] != 'X')
                {
                    bfs[tx][ty] = t.time + 1;
                    q.push(temp);
                }
            }
        }
    }
    if (_min == 100000000)
        cout << "KAKTUS";
    else
        cout << _min;

    return 0;
}
