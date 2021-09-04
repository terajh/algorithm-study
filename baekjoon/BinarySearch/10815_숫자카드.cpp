

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <string.h>
using namespace std;
typedef long long LL;

int arr[500001];
bool bs(int tar, int n)
{
    int left = 0, right = n - 1;
    int mid, res = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == tar)
        {
            res = 1;
            break;
        }
        else if (arr[mid] < tar)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return res;
}
int main()
{

    int n, m, inp;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &inp);
        printf("%d\n", bs(inp, n));
    }

    return 0;
}