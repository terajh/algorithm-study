#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>

#define PIV 1 << 11 // 1~16 N 10만
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int n, m, a, b;
LL tree[PIV * 2];
//0,1,2... 라는 순서를 가지는 배열이 있을때
/// 3번째 값을 6으로 바꿔라

void update(int i, int v)
{
    while (i <= n)
    {
        tree[i] += v;
        i += (i & -i);
    }
}

int sum(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += tree[i];
        i -= (i & -i);
    }
    return res;
}
int query(int l, int r) // 2~7 까지의 구간합
{
    return sum(r) - sum(l - 1);
}

bool comp(pii a, pii b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    else
        return a.first < b.first;
}
int main()
{
    scanf("%d %d", &n, &m);

    vector<pii> v;
    int _max = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        v.push_back({a, b});
        _max = max(_max, b);
    }
    sort(v.begin(), v.end());

    // for (auto i : v)  printf("%d %d\n", i.first, i.second);

    LL res = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (i != v.size() - 1)
        {
            res += query(1, v[i].second - 1);
        }
        // printf("%d %d %d\n", v[i].first, v[i].second, res);
        update(v[i].second, 1);
    }
    printf("%lld\n", res);
}


/*
    세그먼트 트리 또는 인덱스 트리로 풀 수 있다.
    tree update, sum, query 이 3가지만 구현한 뒤
    update 후 가져오기만 하면 되는 간단하지만
    어려운 알고리즘이다.
*/