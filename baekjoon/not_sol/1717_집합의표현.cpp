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

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int ta, tb, tc;
        cin >> ta >> tb >> tc;
        if (ta == 0)
        {
            make_union(tb, tc);
        }
        else
        {
            if (!find_union(tb, tc))
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
}