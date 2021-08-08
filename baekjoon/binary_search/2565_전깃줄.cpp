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


using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, string> tii;
typedef long long LL;

int n;
vector<pii> rope;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		rope.push_back({ a,b });
	}

	sort(rope.begin(), rope.end());

	// 최대의 증가 수열 갯수

	int dp[501];
	for (int k = 0; k < n; k++) {
		dp[k] = 1;
		for (int i = 0; i < k; i++) {
			if (rope[i].second < rope[k].second) {
				dp[k] = max(dp[k], dp[i] + 1);
			}
		}
	}
	sort(dp, dp + n, greater<int>());
	cout << n - dp[0];
	return 0;
}