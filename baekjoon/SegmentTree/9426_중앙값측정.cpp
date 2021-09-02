

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>

#define PIV 1 << 16 // 1~16 N 10만
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int tree[65538 * 2];
//0,1,2... 라는 순서를 가지는 배열이 있을때
/// 3번째 값을 6으로 바꿔라

LL query(int k)
{
    int idx = 1;
    while (idx < PIV)
    {
        idx *= 2;
        if (tree[idx] < k)
        {
            k -= tree[idx], idx += 1;
        }
    }
    idx -= PIV;
    return idx;
}

void update(int n, int v)
{
    n += PIV;
    tree[n] += v;
    while (n >= 1)
    {
        n /= 2;
        tree[n] += v;
    }
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
    int n, k, a, b;
    scanf("%d %d", &n, &k);

    queue<int> q;
    int _max = 0;
    LL res = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &a);
        update(a, 1), q.push(a);
    }
    res += query((k + 1) / 2);

    for (int i = k; i < n; i++)
    {
        scanf("%d", &a);
        update(q.front(), -1), q.pop();
        update(a, 1), q.push(a);
        res += query((k + 1) / 2);
    }
    printf("%lld\n", res);
}

// https://www.acmicpc.net/problem/9426

/*
    세그먼트 트리 사용한 문제이다. update, query 시 특정 방법들을 사용해서
    풀 수 있다.

*/