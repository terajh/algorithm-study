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
typedef pair<int, int> pii;
typedef tuple<int, int, string> tii;

int num[100];
int check[100];
int arr[100];
int n, m;

int get_right_num(int a) {
	return (a >= n) ? 1 : a + 1;
}
int get_left_num(int a) {
	return (a == 1) ? n : a - 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) num[i] = i;
	for (int i = 1; i <= m; i++) cin >> arr[i];
	
	int idx = 1;
	int res = 0, left_idx, right_idx, left_cnt, right_cnt;
	for (int i = 1; i <= m; i++) {
		left_idx = idx, left_cnt = 0;
		right_idx = idx, right_cnt = 0;

		while (num[left_idx] != arr[i]) {
			left_idx = get_left_num(left_idx);
			if (check[left_idx] == 0) left_cnt += 1;
		}

		while (num[right_idx] != arr[i]) {
			right_idx = get_right_num(right_idx);
			if (check[right_idx] == 0) right_cnt += 1;
		}
		
		idx = get_right_num(right_idx);
		while (check[idx] != 0) {
			idx = get_right_num(idx);
		}
		check[right_idx] = 1;
		res += min(left_cnt, right_cnt);
	}
	cout << res;
	return 0;
}