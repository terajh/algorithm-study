

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <string.h>
#include <tuple>

using namespace std;
typedef pair<int, int> pii;

int arr[51][51];
int parent[100001];
int check_[100001];

int check[51][51];

int main()
{
    int n, a, b;
    scanf("%d", &n);
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    check_[1] = 1;
    while (!q.empty())
    {
        int value = q.front();
        q.pop();

        for (int i = 0; i < v[value].size(); i++)
        {
            if (check_[v[value][i]] == 0)
            {
                parent[v[value][i]] = value;
                check_[v[value][i]] = 1;
                q.push(v[value][i]);
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        printf("%d\n", parent[i]);
    }
}