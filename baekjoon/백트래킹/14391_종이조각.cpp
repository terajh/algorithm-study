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
// 입력값이 100만 -> nlogn 으로 끝내야 한다.

int arr[5][5];
int check[5][5];
int dx[] = { -1, 0 };
int dy[] = { 0, -1 };
int n, m;

int setCheck(int x, int y, int mode, int r, int num) {
	vector<int> ans;
	if (mode == 1) {
		for (int i = x; i <= x + r; i++) {
			if (check[i][y] && num == 1) return -1;
		}
		for (int i = x; i <= x + r; i++) {
			check[i][y] = num;
			ans.push_back(arr[i][y]);
		}
	}
	else {
		for (int i = y; i <= y + r; i++) {
			if(check[x][i] && num == 1) return -1;
		}
		for (int i = y; i <= y + r; i++) {
			check[x][i] = num;
			ans.push_back(arr[x][i]);
		}
	}
	int res = 0;
	for (int i = 0; i < ans.size(); i++) {
		res *= 10;
		res += ans[i];
	}
	return res;
}
int maxn = 0;

void bf(int num, int sum) {
	if (num > n * m) {
		maxn = max(sum, maxn);
		return;
	}
	int x, y;
	if (num % n == 0) {
		x = n;
		y = num / n;
	}
	else {
		x = num % n;
		y = num / n + 1;
	}
	
	if (check[x][y] == 1) {
		bf(num + 1, sum);
	}
	else if (check[x][y] == 0) {
		// 해당 원소만
		check[x][y] = 1;
		bf(num + 1, sum + arr[x][y]);
		check[x][y] = 0;

		// 아래 원소 포함
		for (int k = 1; k <= n - x; k++) {
			int tp = setCheck(x, y, 1, k, 1);
			if (tp == -1) continue;
			bf(num + 1, sum + tp);
			setCheck(x, y, 1, k, 0);
		}

		// 오른쪽 원소 포함
		for (int k = 1; k <= m - y; k++) {
			int tp = setCheck(x, y, 2, k, 1);
			if (tp == -1) continue;
			bf(num + 1, sum + tp);
			setCheck(x, y, 2, k, 0);
		}
	}
	maxn = max(sum, maxn);
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %1d", &arr[i][j]);
		}
	}
	bf(1, 0);
	printf("%d\n", maxn);
	return 0;
}