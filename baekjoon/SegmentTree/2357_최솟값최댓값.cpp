#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <vector>
#include <tuple>
#include <string.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long LL;

LL arr[500001];
LL max_tree[500001];
LL min_tree[500001];
LL min_query(LL node, LL s, LL e, LL l, LL r)
{
    if (e < l || r < s)
        return 1000000000;
    if (l <= s && e <= r)
    {
        return min_tree[node];
    }
    else
    {
        return min(min_query(node * 2, s, (s + e) / 2, l, r), min_query(node * 2 + 1, (s + e) / 2 + 1, e, l, r));
    }
}
LL max_query(LL node, LL s, LL e, LL l, LL r)
{
    if (e < l || r < s)
        return 0;
    if (l <= s && e <= r)
    {
        return max_tree[node];
    }
    else
    {
        return max(max_query(node * 2, s, (s + e) / 2, l, r), max_query(node * 2 + 1, (s + e) / 2 + 1, e, l, r));
    }
}

void update(LL node, LL s, LL e, LL idx, LL v)
{
    if (idx < s || idx > e)
        return;
    if (s == e)
    {
        max_tree[node] = v;
        min_tree[node] = v;
    }
    else
    {
        update(node * 2, s, (s + e) / 2, idx, v);
        update(node * 2 + 1, (s + e) / 2 + 1, e, idx, v);
        max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
        min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
    }
}

int main()
{
    LL n, l, a, b;
    scanf("%lld %lld", &n, &l);

    for (LL i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        update(1, 1, n, i, arr[i]);
    }
    for (LL i = 0; i < l; i++)
    {
        scanf("%lld %lld", &a, &b);
        printf("%lld ", min_query(1, 1, n, a, b));
        printf("%lld\n", max_query(1, 1, n, a, b));
    }
    return 0;
}