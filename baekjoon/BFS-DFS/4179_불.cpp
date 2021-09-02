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

char arr[1001][1001];
int check[1001][1001];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int h, w, sx, sy, fx, fy;
int n, m;

// 불의 위치에서 탐색
void fire_bfs(int x, int y) {
    queue<tiii> q;
    q.push({ x, y, 0 });
    check[x][y] = 0;

    while (!q.empty()) {
        tiii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cx = get<0>(cur) + dx[i];
            int cy = get<1>(cur) + dy[i];

            if (cx < 1 || cx > n || cy < 1 || cy > n) continue;
            if (arr[cx][cy] == '#') continue;
            if (check[cx][cy] != -1 && check[cx][cy] <= get<2>(cur) + 1) continue;
            // 이미 불이 번진 상태이면 건너뛴다.

            check[cx][cy] = get<2>(cur) + 1;
            q.push({ cx, cy, check[cx][cy] });
        }
    }
}
// 지훈이의 위치에서 탐색
int go_bfs(int x, int y) {
    queue<tiii> q;
    q.push({ x, y, 0 });
    int answer = INF;
    while (!q.empty()) {
        tiii cur = q.front();
        int cur_x = get<0>(cur);
        int cur_y = get<1>(cur);
        int cur_tm = get<2>(cur);
        q.pop();

        if (cur_x == 1 || cur_x == n || cur_y == 1 || cur_y == m) {
            answer = min(answer, cur_tm + 1);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int cx = get<0>(cur) + dx[i];
            int cy = get<1>(cur) + dy[i];

            if (cx < 1 || cx > n || cy < 1 || cy > m) continue;
            if (arr[cx][cy] != '.') continue;
            if (check[cx][cy] != -1 && check[cx][cy] <= get<2>(cur) + 1) continue;
            // 불이 이미 번져있는 곳이면 갈 수 없다.

            check[cx][cy] = get<2>(cur) + 1;
            q.push({ cx, cy, get<2>(cur) + 1 });
        }
    }
    return answer;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    string tp;
    vector<pii> fire;
    pii now;

    for (int i = 1; i <= n; i++) {
        cin >> tp;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = tp.at(j - 1);
            if (arr[i][j] == 'F') {
                fire.push_back({ i,j });
            }
            else if (arr[i][j] == 'J') {
                now = { i,j };
            }
        }
    }

    memset(check, -1, sizeof(check));
    for (auto pi : fire)
        fire_bfs(pi.first, pi.second);

    int ans = go_bfs(now.first, now.second);
    if (ans == INF) cout << "IMPOSSIBLE";
    else cout << ans;


    return 0;
}