#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
char arr[51][51];
int check[51][51];
int visit[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void input(int &n, int &m)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = a[j];
        }
    }
}

int _max = 0;
bool hasCycle = false;
int dfs(int x, int y, int n, int m)
{

    if (x < 0 || x >= n || y < 0 || y >= m)
        return 0;
    if (arr[x][y] == 'H')
        return 0;
    if (visit[x][y] == 1)
    {
        hasCycle = true;
        return -1;
    }

    int &ret = check[x][y]; 
    // 이렇게 레퍼런스 선언하면 ret 값 바뀔 시 배열의 값도 바뀐다.
    if (ret != -1)
        return ret;

    visit[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i] * (arr[x][y] - '0');
        int ty = y + dy[i] * (arr[x][y] - '0');
        ret = max(ret, dfs(tx, ty, n, m) + 1);
    }
    visit[x][y] = 0;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    input(n, m);

    memset(check, -1, sizeof(check));
    int result = dfs(0, 0, n, m);

    if (hasCycle)
    {
        cout << -1;
    }
    else
    {
        cout << result;
    }
    return 0;
}