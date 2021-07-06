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
long arr[1000000];
long input()
{
    long maxEl = 0;
    long minEl = 2000000000;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxEl = max(maxEl, arr[i]);
        minEl = min(minEl, arr[i]);
    }
    return maxEl;
}

bool calc(long h)
{
    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > h)
            sum += arr[i] - h;
        if (sum >= m)
            return true;
    }
    return false;
}

int main()
{

    long max_element = input();
    long left = 0;
    long right = 1000000000;
    long mx = 0;

    while (left <= right)
    {
        long mid = (left + right) / 2;
        if (calc(mid))
        {
            left = mid + 1;
            mx = max(mx, mid);
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << mx;

    return 0;
}