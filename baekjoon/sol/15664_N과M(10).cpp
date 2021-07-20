#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>
#include <math.h>
#include <map>

using namespace std;
typedef long long LL;

int arr[9];
int check[9];
int _max[9];
int n, m;
map<int, int> ma;
vector<int> v;

void dfs(int k, int c)
{
    if (c == m)
    {
        int sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (i != v.size() - 1 && v[i] > v[i + 1])
                return;
            sum *= 10;
            sum += v[i];
        }
        if (ma[sum] == 0)
        {
            for (int i = 0; i < v.size(); i++)
            {
                printf("%d ", v[i]);
            }
            printf("\n");
            ma[sum] = 1;
            return;
        }
        else
            return;
    }

    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0)
        {
            check[i] = 1;
            v.push_back(arr[i]);
            dfs(k + 1, c + 1);
            v.pop_back();
            check[i] = 0;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    dfs(0, 0);
}