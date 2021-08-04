#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <set>

typedef long long ll;
using namespace std;

ll a_arr[1001];
ll b_arr[1001];
int a, b;
ll n;
void input()
{
    cin >> n;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> a_arr[i];
    }
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        cin >> b_arr[i];
    }
}
int main()
{
    input();

    vector<ll> asum;
    vector<ll> bsum;

    for (int i = 0; i < a; i++)
    {
        ll sum = 0;
        for (int j = i; j < a; j++)
        {
            sum += a_arr[j];
            asum.push_back(sum);
        }
    }

    for (int i = 0; i < b; i++)
    {
        ll sum = 0;
        for (int j = i; j < b; j++)
        {
            sum += b_arr[j];
            bsum.push_back(sum);
        }
    }

    sort(asum.begin(), asum.end());
    sort(bsum.begin(), bsum.end());

    ll res = 0;
    for (int i = 0; i < asum.size(); i++)
    {
        auto lb = lower_bound(bsum.begin(), bsum.end(), n - asum[i]);
        auto ub = upper_bound(bsum.begin(), bsum.end(), n - asum[i]);
        if (lb == ub)
        {
            continue;
        }
        else
        {
            res += ub - lb;
        }
    }
    cout << res;

    return 0;
}