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
int arr[11][11];
int check[11][11];
vector<pii> one;
int card[] = { 0,5,5,5,5,5 };
int cnt;

bool queryPaper(int k, int tx, int ty) {
    for (int x = 0; x < k; x++) {
        for (int y = 0; y < k; y++) {
            int cx = tx + x;
            int cy = ty + y;
            if (arr[cx][cy] != 1 || check[cx][cy] == 1) return false;
        }
    }
    return true;
}
void checkPaper(int k, int tx, int ty) {
    for (int x = 0; x < k; x++) {
        for (int y = 0; y < k; y++) {
            int cx = tx + x;
            int cy = ty + y;
            check[cx][cy] = 1;
        }
    }
}

void uncheckPaper(int k, int tx, int ty) {
    for (int x = 0; x < k; x++) {
        for (int y = 0; y < k; y++) {
            int cx = tx + x;
            int cy = ty + y;
            check[cx][cy] = 0;
        }
    }
}

int res = 1000;
void dfs(int z, int c) {
    if (z >= (int)one.size()) {
        res = min(c, res);
        return;
    }
    int tx = one[z].first;
    int ty = one[z].second;
    if (check[tx][ty] == 1) dfs(z + 1, c);
    else {
        for (int k = 5; k >= 1; k--) {
            if (queryPaper(k, tx, ty)) {
                if (card[k] == 0) continue;
                else {
                    card[k] -= 1;
                    checkPaper(k, tx, ty);
                    dfs(z + 1, c + 1);
                    card[k] += 1;
                    uncheckPaper(k, tx, ty);
                }
            }
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) one.push_back({ i,j });
        }
    }

    if (one.empty()) cout << 0;
    else {
        dfs(0, 0);
        if (res == 1000) cout << -1;
        else cout << res;
    }
    return 0;
}