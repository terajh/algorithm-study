#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>

#define INF 100000000

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int arr[100001];
int check[100001];

int bfs(int x, vector<vector<int>> &node) {
    queue<int> q;
    int res = 1;
    q.push(x);
    check[x] = 1;
    while (!q.empty()) {
        int cx = q.front();
        q.pop();

        for (int i = 0; i < node[cx].size(); i++) {
            int nx = node[cx][i];
            if (check[nx] == 1) continue;
            check[nx] = 1;
            res += 1;
            q.push(nx);
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    int to, from;
    vector<vector<int>> node(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> to >> from;
        node[from].push_back(to);
    }

    int answer = 0, color = 0;
    priority_queue <pii> pq;
    pq.push({ 0,0 });
    for (int i = 1; i <= n; i++) {
        memset(check, 0, sizeof(check));
        int cc = bfs(i, node);
        if (pq.top().first < cc) {
            while (!pq.empty() && pq.top().first < cc) {
                pq.pop();
            }
            pq.push({ cc, -i });
        }
        else if (pq.top().first == cc) {
            pq.push({ cc, -i });
        }
    }

    while (!pq.empty()) {
        cout << -pq.top().second << " ";
        pq.pop();
    }
    return 0;
}