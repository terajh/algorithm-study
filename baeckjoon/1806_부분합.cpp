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

long arr[100001];
int main()
{

    int n;
    long s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long sum = 0;
    int _min = 100000000;

    for (int lo = 0, hi = 0; hi < n;)
    {
        sum += arr[hi++];
        while (sum > s)
        {
            _min = min(_min, hi - lo);
            sum -= arr[lo++];
        }
        if (sum == s)
        {
            _min = min(_min, hi - lo);
        }
    }
    if (_min != 100000000)
    {
        cout << _min;
    }
    else
    {
        cout << 0;
    }
    return 0;
}