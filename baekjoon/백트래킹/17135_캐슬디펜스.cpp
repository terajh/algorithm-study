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
int n, m, d;
int arr[17][17];
int check[16][16];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
vector<pii> am;
int maxn = 0;
pii arc_pos;
int cur_time;

bool compare(pii a, pii b) {
	int ta = abs(a.first + cur_time - arc_pos.first) + abs(a.second - arc_pos.second);
	int tb = abs(b.first + cur_time - arc_pos.first) + abs(b.second - arc_pos.second);
	if (ta == tb) {
		return a.second < b.second;
	}
	else {
		return ta < tb;
	}
}
int getAnmy(vector<pii> &arc) {
	int res = 0;
	int am_check[17][17] = { 0, };
	int checked[17][17] = { 0, };
	// 시간 [0, n)
	for (int t = 0; t < n; t++) {
		vector<pii> shoted;
		// 적 위치 -> 각 궁수들은 자신과 가장 가까운 놈을 찾아야함
		for (int j = 0; j < arc.size(); j++) {
			int ax = arc[j].first;
			int ay = arc[j].second;
			arc_pos = { ax, ay };
			cur_time = t;
			sort(am.begin(), am.end(), compare);

			for (auto pos : am) {
				int sx = pos.first;
				int sy = pos.second;
				if (sx + t > n) continue;
				if (abs(sx + t - ax) + abs(sy - ay) > d) break;
				if (checked[sx][sy]) continue;
				if (am_check[sx][sy] == 0)
					shoted.push_back({ sx, sy });
				am_check[sx][sy] = 1;
				break;
			}
			
		}

		for (int j = 0; j < shoted.size(); j++) {
			int tx = shoted[j].first;
			int ty = shoted[j].second;
			checked[tx][ty] = 1;
			res += 1;
		}
	}
	
	
	
	return res;
}
void bt(int num, int cnt, vector<pii> &arc) {
	int x = n+1, y = num;

	if (cnt == 3) {
		int res = getAnmy(arc);
		maxn = max(res, maxn);
		return;
	}
	if (num > m) return;

	arc.push_back({ x, y });
	bt(num + 1, cnt + 1, arc);
	arc.pop_back();
	bt(num + 1, cnt, arc);
}

int main() {
	scanf("%d %d %d", &n, &m, &d);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j]) 
				am.push_back({ i,j });
		}
	}
	vector<pii> arc;
	bt(1, 0, arc);
	printf("%d\n", maxn);
	return 0;
}