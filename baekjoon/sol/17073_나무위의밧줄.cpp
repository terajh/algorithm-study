#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
#include <map>

#define INF 100000000

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef long long LL;
bool check[500001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int a, b;
    vector<vector<int>> tree(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    check[1] = true;
    int sum = 0, cnt = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int child_check = 0;
        for (int i = 0; i < tree[cur].size(); i++) {
            int next = tree[cur][i];
            if (check[next]) continue;
            check[next] = true;
            child_check += 1;
            q.push(next);
        }
        if (child_check == 0) {
            cnt += 1;
        }
    }
    double res = (double)k / (double)cnt;
    printf("%lf", res);

    return 0;
}