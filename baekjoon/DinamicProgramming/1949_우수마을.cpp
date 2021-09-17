#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

#define MAX_INT 1000000000
using namespace std;

typedef pair<int, int> pii;
int arr[10001];
int check[10001];
int dp[10001][2];

void dfs(int x, vector<vector<int>> &v) {
    for (int i = 0; i < v[x].size(); i++) {
        int nx = v[x][i];
        if (check[nx]) continue;
        check[nx] = 1;
        dfs(nx, v);
        dp[x][0] += dp[nx][1];
        dp[x][1] += max(dp[nx][0], dp[nx][1]);
    }
    dp[x][0] += arr[x];
    return;
}
int main() {
    int n;
    cin >> n; 
    vector<vector<int>> v(n+1);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    int a, b;
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    check[1] = 1;
    dfs(1, v);

    printf("%d", max(dp[1][0], dp[1][1]));
    return 0;
}