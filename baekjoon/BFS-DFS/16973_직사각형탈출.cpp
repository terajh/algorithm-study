#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>

#define INF 100000000

using namespace std;
typedef pair<int, int> pii;
struct Square {
    int x, y;
    int tm;
};

Square initSquare(int _x, int _y, int _tm) {
    Square tp;
    tp.x = _x;
    tp.y = _y;
    tp.tm = _tm;
    return tp;
}

int arr[1001][1001];
int check[1001][1001];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int h, w, sx, sy, fx, fy;
int n, m;

bool checkSquare(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    if (y + w - 1 > m || x + h - 1 > n) return false;
    
    for (int i = x; i < x + h; i++) {
        if (arr[i][y] == 1) return false;
        if (arr[i][y + w - 1] == 1) return false;
    }

    for (int i = y; i < y + w; i++) {
        if (arr[x][i] == 1) return false;
        if (arr[x + h - 1][i] == 1) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> h >> w >> sx >> sy >> fx >> fy;

    queue<Square> q;
    q.push(initSquare(sx, sy, 0));
    int answer = INF;
    while (!q.empty()) {
        Square tp = q.front();
        q.pop();

        if (tp.x == fx && tp.y == fy) {
            answer = min(answer, tp.tm);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int cx = tp.x + dx[i];
            int cy = tp.y + dy[i];
            if (check[cx][cy] == 1) continue;
						// 직사각형의 범위에 벽이 있는지 체크하는 checkSquare
            if (!checkSquare(cx, cy)) continue;

            check[cx][cy] = 1;
            q.push(initSquare(cx, cy, tp.tm + 1));
        }
    }

    if (answer == INF) cout << -1;
    else cout << answer;

    return 0;
}