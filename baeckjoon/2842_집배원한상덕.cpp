#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <set>

typedef long long LL;
using namespace std;

vector<int> height;
int post_x, post_y, cnt_x;
int x;
char vil[51][51];
int cost[51][51];

int dx[] = { 0,1,0,-1,1,1,-1,-1 };
int dy[] = { 1,0,-1,0 ,1,-1,1,-1 };

int bfs(int lo, int hi) {
	queue<pair<int, int>> q;
	bool check[51][51] = { false, };

	q.push({ post_x, post_y });
	check[post_x][post_y] = true;
	if (cost[post_x][post_y] < lo || cost[post_x][post_y] > hi) return -1;
	int cnt = 0;
	while (!q.empty() ) {
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();

		if (vil[qx][qy] == 'K') {
			cnt++;
		}
		for (int i = 0; i < 8; i++) {
			int tx = qx + dx[i];
			int ty = qy + dy[i];
			if (tx < 0 || tx >= x || ty < 0 || ty >= x) continue;
			if (cost[tx][ty] < lo || cost[tx][ty] > hi) continue;
			if (check[tx][ty] == true) continue;

			check[tx][ty] = true;
			q.push({ tx, ty });
		}
	}
	return cnt;
}

void input() {
	cin >> x;
	for (int i = 0; i < x; i++) {
		scanf("%s", vil[i]);
		for (int j = 0; j < x; j++) {
			if (vil[i][j] == 'P') {
				post_x = i;
				post_y = j;
			}
			else if (vil[i][j] == 'K') {
				cnt_x++;
			}
		}
	}
	int _max = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			cin >> cost[i][j];
			height.push_back(cost[i][j]);
		}
	}
	sort(height.begin(), height.end());
	return;
}


int main() {
	input();
	int _min = height.back() - height[0];

	for (int lo = 0, hi = 0; lo < height.size() && hi < height.size() && lo <= hi;) {
		int cnt = bfs(height[lo], height[hi]);
		if (cnt == cnt_x) {
			_min = min(_min, height[hi] - height[lo]);
			lo++;
		}
		else if(cnt < cnt_x){
			hi++;
		}
		else {
			lo++;
		}
		
	}
	cout << _min;

	return 0;
}