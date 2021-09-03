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
int visit[100001];
int n, t;

int dfs(int x, int color, int cnt) {
    int next = arr[x];
    if (check[next]) {
        if (check[next] == color) {
            return cnt - visit[next];
        }
        else return 0;
    }
    else if (!check[next]) {
        check[next] = color;
        visit[next] = cnt;
        return dfs(next, color, cnt+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        memset(check, 0, sizeof(check));
        for (int j = 1, input ; j <= n; j++) {
            cin >> arr[j];
        }
        int res = n;
        for (int j = 1, color = 1; j <= n; j++) {
            if (check[j] == 0) {
                check[j] = color;
                visit[j] = 0;
                res -= dfs(j, color++, 1);
            }
        }

        cout << res << endl;
    }



    return 0;
}