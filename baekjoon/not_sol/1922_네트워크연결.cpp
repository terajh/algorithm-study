#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>
#include <math.h>
#include <map>
#include <string.h>

#define R 0
#define U 1
using namespace std;
int n, m;
int arr[1000001];

int get_union(int a)
{
    if (arr[a] == a)
        return a;
    else
        return arr[a] = get_union(arr[a]);
}

void make_union(int a, int b)
{
    a = get_union(a);
    b = get_union(b);
    if (a == b)
        return;
    else
        arr[b] = a;
}

bool find_union(int a, int b)
{
    a = get_union(a);
    b = get_union(b);
    if (a == b)
        return true;
    else
        return false;
}

struct node
{
    int to;
    int from;
    int cost;
};

vector<node> v;

bool compare(node a, node b)
{
    return a.cost < b.cost;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    for (int i = 0; i < m; i++)
    {
        node t;
        scanf("%d %d %d", &t.to, &t.from, &t.cost);
        v.push_back(t);
    }
    sort(v.begin(), v.end(), compare);

    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (!find_union(v[i].from, v[i].to))
        {
            make_union(v[i].from, v[i].to);
            res += v[i].cost;
        }
    }
    cout << res;
}