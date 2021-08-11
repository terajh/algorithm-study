#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <tuple>
#include <string>
#include <string.h>
#include <stack>
#include <set>
#include <map>


using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
typedef tuple<int, int, string> tii;

int n, s;
int arr[41];
int check[41];
LL ans;
map<int,int> res;

void left_dfs(int x, int val) {
	if (x == n/2) {
		res[val]++;
		return;
	}
	// 1. x번째를 더하는 경우
	left_dfs(x + 1, val + arr[x]);
	// 2. x번째를 더하지 않는 경우
	left_dfs(x + 1, val);
}
void right_dfs(int x, int val) {
	if (x == n) {
		ans += res[s - val];
		// 있으면 그 값만큼 더해지고 없으면 0 더해짐
		return;
	}
	// 1. x번째를 더하는 경우
	right_dfs(x + 1, val + arr[x]);
	// 2. x번째를 더하지 않는 경우
	right_dfs(x + 1, val);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	left_dfs(0, 0);
	right_dfs(n / 2, 0);

	if (s == 0) ans--;
	cout << ans;
	return 0;
}