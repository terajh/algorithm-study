#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <set>

using namespace std;
int n, m;
int city[51][51];
int check[14];
typedef pair<int, int> pii;
vector<pii> chic;
vector<pii> home;

int calc()
{
    int sum = 0;
    for (int j = 0; j < home.size(); j++)
    {
        int x = home[j].first;
        int y = home[j].second;
        int tsum = 100000;
        for (int i = 0; i < 14; i++)
        {
            if (check[i] == 1)
            {
                int dx = abs(x - chic[i].first);
                int dy = abs(y - chic[i].second);
                tsum = min(tsum, dx + dy);
            }
        }
        sum += tsum;
    }

    return sum;
}

int _min = 100000;
int chic_count = 0;
void dfs(int pos)
{
    if (chic_count == m)
    {
        _min = min(_min, calc());
        return;
    }
    for (int i = pos; i < chic.size(); i++)
    {
        // 1. 치킨집 check memo 되어있는지 확인
        if (check[i] == 1)
            continue;
        check[i] = 1;
        chic_count += 1;
        dfs(i);
        check[i] = 0;
        chic_count -= 1;
    }
}
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> city[i][j];
            if (city[i][j] == 2)
                chic.push_back({i, j});
            else if (city[i][j] == 1)
                home.push_back({i, j});
        }
    }
}
void solution()
{

    dfs(0);
    cout << _min;
}
int main()
{
    input();
    solution();

    return 0;
}