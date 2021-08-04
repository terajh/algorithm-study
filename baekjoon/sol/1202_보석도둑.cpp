#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
int n, k;

int main()
{
    ios_base::sync_with_stdio(0);

    cin.tie(0); //cin 실행속도 향상

    scanf("%d %d", &n, &k);
    vector<pii> jewl;
    vector<LL> bag;
    priority_queue<LL> pq;

    LL m, v, t;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> v;
        jewl.push_back({m, v});
    }

    for (int i = 0; i < k; i++)
    {
        cin >> t;
        bag.push_back(t);
    }
    sort(bag.begin(), bag.end());
    sort(jewl.begin(), jewl.end());

    long long answer = 0;
    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        while (idx < n && jewl[idx].first <= bag[i])
        {
            // 2. 가방에 넣을 수 있는지, 없는지 확인
            pq.push(jewl[idx++].second);
        }
        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }

    // 1. 가장 작은 가방 기준
    cout << answer;

    return 0;
}