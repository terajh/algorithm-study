#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int n;
vector<string> v;
vector<char> alpha;
int check[10];
set<char> s;
map<char, int> m;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string tp;
        cin >> tp;
        v.push_back(tp);
        for (int j = 0; j < tp.size(); j++)
        {
            s.insert(tp[j]);
        }
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        alpha.push_back(*it);
    }
}
int _max = 0;
void dfs(int pos)
{
    if (pos == (int)alpha.size())
    {
        int sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            string tp = v[i];
            int tsum = 0;
            for (int j = 0; j < tp.size(); j++)
            {
                tsum *= 10;
                tsum += m[tp[j]];
            }
            sum += tsum;
        }
        _max = max(_max, sum);
        return;
    }

    for (int i = 9; i >= 0; i--)
    {
        // 1. 해당 숫자가 쓰이고 있는지 확인
        if (check[i]) continue;
        check[i] = 1;
        m[alpha[pos]] = i;
        dfs(pos + 1);
        check[i] = 0;
        m[alpha[pos]] = 0;
    }
}

void solution()
{
    dfs(0);
    cout << _max;
}
int main()
{
    input();
    solution();

    return 0;
}