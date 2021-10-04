#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_NUM 1000000009
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int n;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1,-1,0,0 };
double pri[4];
double res = 0;
int arr[100][100];
int check[100][100];
int cc = 0;
void bt(int x, int y, int cnt, double sum) {
	if (cnt >= n) {
		res += sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (check[cx][cy]) continue;
		check[cx][cy] = 1;
		bt(cx, cy, cnt + 1, sum * pri[i]);
		check[cx][cy] = 0;
	}
}
int main() {
	cout.precision(11);
	cin >> n >> pri[0] >> pri[1] >> pri[2] >> pri[3];
	for (int i = 0; i < 4; i++)
		pri[i] /= 100;

	check[50][50] = 1;
	bt(50, 50, 0, 1);
	cout << res;


	return 0;
}