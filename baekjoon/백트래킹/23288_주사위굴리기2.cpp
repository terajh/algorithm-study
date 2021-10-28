#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int arr[21][21];
int check[21][21];

pii pos = { 0, 1 };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int n, m, k;
//   2
// 4 1 3
//   5
//   6 // 6 > 1

//   2
// 6 4 1
//   5
//   3  // 3 > 1

//   3
// 6 2 1
//   4
//   5  // 5 < 6

//   3
// 2 1 5
//   4
//   6

struct Dice {
    int top = 1;
    int bottom = 6;
    int tr = 3, tl = 4;
    int tu = 2, td = 5;
    Dice(int a1, int a2, int a3, int a4, int a5, int a6)
        : top(a1), bottom(a2), tr(a3), tl(a4), tu(a5), td(a6) {};
};

Dice rotDice(Dice tp) {
    Dice res(0, 0, 0, 0, 0, 0);
    if (pos.first == -1 && pos.second == 0) {
        // up
        res.top = tp.td;
        res.bottom = tp.tu;
        res.td = tp.bottom;
        res.tu = tp.top;
        res.tr = tp.tr;
        res.tl = tp.tl;
    }
    else if (pos.first == 1 && pos.second == 0) {
        // down
        res.top = tp.tu;
        res.bottom = tp.td;
        res.td = tp.top;
        res.tu = tp.bottom;
        res.tr = tp.tr;
        res.tl = tp.tl;
    }
    else if (pos.first == 0 && pos.second == 1) {
        // right
        res.tu = tp.tu;
        res.td = tp.td;
        res.tr = tp.top;
        res.tl = tp.bottom;
        res.top = tp.tl;
        res.bottom = tp.tr;
    }
    else if (pos.first == 0 && pos.second == -1) {
        // left
        res.tu = tp.tu;
        res.td = tp.td;
        res.tl = tp.top;
        res.tr = tp.bottom;
        res.top = tp.tr;
        res.bottom = tp.tl;
    }
    return res;
}

void transPos(int mode) {
    pii res = { pos.first, pos.second };
    if (mode == 1) {
        // 0 1 
        // -1 0
        res.first = pos.second;
        res.second = -pos.first;
    }
    else if (mode == 2) {
        res.first = -pos.second;
        res.second = pos.first;
    }
    pos = res;
    return;
}

int getScore(int x, int y) {
    if (check[x][y]) return check[x][y];
    queue<pii> q;
    q.push({ x, y });
    check[x][y] = 1;
    int target = arr[x][y];
    int res = 1;
    vector<pii> v = { {x, y} };

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = cx + dx[i];
            int ty = cy + dy[i];
            if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
            if (arr[tx][ty] != target) continue;
            if (check[tx][ty]) continue;

            res += 1;
            check[tx][ty] = 1;
            q.push({ tx, ty });
            v.push_back({ tx, ty });
        }
    }

    for (int i = 0; i < v.size(); i++) {
        check[v[i].first][v[i].second] = res;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    queue<pii> q;
    q.push({ 1, 1 });
    int cur_rot = 3, res = 0;
    Dice dice(1, 6, 3, 4, 2, 5);


    for (int i = 0; i < k; i++) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        int tx = cx + pos.first;
        int ty = cy + pos.second;
        if (tx < 1 || ty < 1 || tx > n || ty > m) {
            pos.first = -pos.first;
            pos.second = -pos.second;
        };
        tx = cx + pos.first;
        ty = cy + pos.second;

        dice = rotDice(dice);
        
        if (dice.bottom > arr[tx][ty])
            transPos(1);
        else if (dice.bottom < arr[tx][ty])
            transPos(2);

        if (check[tx][ty]) res += check[tx][ty] * arr[tx][ty];
        else res += getScore(tx, ty) * arr[tx][ty];

        q.push({ tx, ty });

    }

    cout << res;
}