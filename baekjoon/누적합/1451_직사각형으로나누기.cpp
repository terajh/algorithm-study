#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int arr[101][101];
int sum[101][101];
vector<int> in;
// 입력값이 100만 -> nlogn 으로 끝내야 한다.
LL maxnn = 0;
int getSum(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}
void dfs(int cx1, int cy1, int cx2, int cy2, int cnt, vector<int> &ans) {
	if (cnt == 3) {
		LL res = 1;
		for (auto i : ans) {
			res *= (LL)i;
		}
		maxnn = max(maxnn, res);
		return;
	}

	for (int i = cx1; i < cx2; i++) {
		// 왼쪽 직사각형 체킹
		// (cx1, cy1) - (i, cy2)
		ans.push_back(getSum(cx1, cy1, i, cy2));
		dfs(i+1, cy1, cx2, cy2, cnt + 1, ans);
		ans.pop_back();

		// 오른쪽 직사각형 체킹
		// (i+1, cy1) - (cx2, cy2)
		ans.push_back(getSum(i + 1, cy1, cx2, cy2));
		dfs(cx1, cy1, i, cy2, cnt + 1, ans);
		ans.pop_back();
		
	}

	for (int i = cy1; i <= cy2; i++) {
		// 위쪽 직사각형 체킹
		// (cx1, cy1) - (cx2, i)
		ans.push_back(getSum(cx1, cy1, cx2, i));
		dfs(cx1, i+1, cx2, cy2, cnt + 1, ans);
		ans.pop_back();
		// 아래쪽 직사각형 체킹

		// (cx1, i) - (cx2, cy2)
		ans.push_back(getSum(cx1, i+1, cx2, cy2));
		dfs(cx1, cy1, cx2, i, cnt + 1, ans);
		ans.pop_back();
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %1d", &arr[i][j]);
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + arr[i][j] - sum[i - 1][j - 1];
		}
	}

	vector<int> ans;
	vector<int> in;
	dfs(1, 1, n, m, 0, ans);
	printf("%lld\n", maxnn);
	return 0;
}