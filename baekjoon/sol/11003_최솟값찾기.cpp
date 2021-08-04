#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <set>

typedef long long LL;
using namespace std;

int n, l;
int arr[5000000];
deque<pair<int, int>> dq;

int main()
{
    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.front().second < i - l + 1)
        {
            dq.pop_front();
        }
        while (!dq.empty() && dq.back().first > arr[i])
        {
            dq.pop_back();
        }
        dq.push_back({arr[i], i});
        printf("%d ", dq.front().first);
    }

    return 0;
}