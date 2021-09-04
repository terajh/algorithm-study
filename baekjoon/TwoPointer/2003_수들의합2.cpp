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
int arr[10000];
void input(int &n, int &m)
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return;
}
int main()
{
    int n, m;
    input(n, m);

    int sum = 0;
    int result = 0;
    for (int lo = 0, hi = 0; hi < n; hi++)
    {
        sum += arr[hi];
        while (sum > m)
            sum -= arr[lo++];
        if (sum == m)
            result++;
    }
    cout << result;

    return 0;
}