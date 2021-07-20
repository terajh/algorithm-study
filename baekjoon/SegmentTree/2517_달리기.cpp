#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int player_num;
int tree[1 << 20];
pii player[500001];

int seg_sum(int node, int s, int e, int l, int r){
    if (r < s || e < l)
        return 0;
    if (l <= s && e <= r) {
        return tree[node];
    }
    else {
        return seg_sum(node * 2, s, (s + e) / 2, l, r) 
        + seg_sum(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
    }
}

void update(int node, int s, int e, int idx, int v)
{
    if (idx < s || e < idx)
        return;
    // leaf node 인지 확인
    if (s == e) {
        tree[node] = v;
        // 그 때 그 때 다르다.
        // v 만큼 뺴는 경우도 있고, XOR 하는 경우도 있고
        // 곱하는 경우, AND 연산하는 경우 등등 많다.
    }
    else {
        update(node * 2, s, (s + e) / 2, idx, v);
        update(node * 2 + 1, (s + e) / 2 + 1, e, idx, v);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

bool comp(pii p1, pii p2)
{
    return p1.second < p2.second;
}

int main(){
    scanf("%d", &player_num);
    for (int i = 0; i < player_num; i++)
    {
        int power;
        cin >> power;
        player[i] = make_pair(i, power);
    }
    sort(player, player + player_num, comp);

    int num = 0;
    // sort power --> relabelling
    for (int i = 0; i < player_num; i++)
    {
        player[i].second = ++num;
    }
    // sort original order -> 원래대로 복구시킨다.
    sort(player, player + player_num);

    for (int i = 0; i < player_num; i++)
    {
        int curpower = player[i].second;
        int cnt = 0;
        if (curpower > 1) {
            cnt = seg_sum(1, 1, num, 1, curpower - 1);
        }
        update(1, 1, num, curpower, 1);
        printf("%d\n", i + 1 - cnt);
    }
    // debug

    return 0;
}