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

LL x;
LL y;
int arr[5000000];
deque<pair<int, int>> dq;

int isok(LL z, LL d)
{
    int _output = (100 * (y + d)) / (x + d);
    if (_output == z)
        return 0;
    else if (_output > z)
        return 1;
    else
        return -1;
}
int main()
{
    cin >> x >> y;

    LL z = (100 * y) / x;
    LL left = 1;
    LL right = x;

    while (left <= right)
    {
        LL mid = (left + right) / 2;
        int ok = isok(z, mid);
        if (ok == 1)
        {
            right = mid - 1;
        }
        else if (ok == -1 || ok == 0)
        {
            left = mid + 1;
        }
    }
    if (left > x)
    {
        cout << -1;
    }
    else
    {
        cout << left;
    }

    return 0;
}