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
typedef long l;
using namespace std;

vector<ll> a;
vector<ll> b;
vector<ll> c;
vector<ll> d;
vector<ll> ab;
vector<ll> cd;

void input(ll &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll tp, tp1, tp2, tp3;
        cin >> tp >> tp1 >> tp2 >> tp3;
        a.push_back(tp);
        b.push_back(tp1);
        c.push_back(tp2);
        d.push_back(tp3);
    }
}
int main()
{
    ll n;
    input(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    long long result = 0;
    for (int i = 0; i < ab.size(); i++)
    {
        auto lb = lower_bound(cd.begin(), cd.end(), -1 * ab[i]);
        auto ub = upper_bound(cd.begin(), cd.end(), -1 * ab[i]);

        if (lb == ub)
        { // 없는 경우
            continue;
        }
        else
        {
            result += ub - lb;
        }
    }

    cout << result;
    return 0;
}