#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

typedef pair<int, int> pii;
int n, m;
int arr[51][51];
int check[51][51];
int vcheck[11];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int minn = 10000;
vector<pii> virus;
struct Node {
	int x, y, time;
};
Node initNode(int x, int y, int time) {
	Node tp;
	tp.x = x;
	tp.y = y;
	tp.time = time;
	return tp;
}
void bt(int idx,  vector<pii> &vi) {
	if ((int)vi.size() == m) {
		queue<Node> q;
		memset(check, 0, sizeof(check));

		for (auto i : vi) {
			q.push(initNode(i.first, i.second, 0));
			check[i.first][i.second] = 1;
		}
		int maxn = 0;
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			int ctime = q.front().time;
			q.pop();
			maxn = max(maxn, ctime);
			for (int i = 0; i < 4; i++) {
				int tx = cx + dx[i];
				int ty = cy + dy[i];
				if (tx < 1 || tx > n || ty < 1 || ty > n) continue;
				if (check[tx][ty]) continue;
				if (arr[tx][ty] == 1) continue;

				check[tx][ty] = 1;
				q.push(initNode(tx, ty, ctime + 1));
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] == 0 && check[i][j] == 0) {
					maxn = -1;
				}
			}
		}
		if (maxn != -1) {
			minn = min(minn, maxn);
		}
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		vi.push_back(virus[i]);
		bt(i + 1, vi);
		vi.pop_back();
	}
}
int main() {
	scanf("%d %d", &n, &m);

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}
			if (arr[i][j] == 0) {
				res += 1;
			}
		}
	}
	vector<pii> vi;
	bt(0, vi);
	printf("%d\n", (minn == 10000) ? -1 : minn);
}