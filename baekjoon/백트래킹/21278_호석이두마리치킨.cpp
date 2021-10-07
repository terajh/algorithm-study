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
int check[101];
vector<vector<int>> node(101);
pii ans = { 0,0 };
int minn = 100000;
void bt(int idx, vector<int> &chic) {
	if ((int)chic.size() == 2) {
		// bfs 탐색
		// printf("%d %d\n", chic[0], chic[1]);
		memset(check, -1, sizeof(check));
		queue<pii> q;
		for (int i = 0; i < chic.size(); i++) {
			q.push({ chic[i], 0 });
			check[chic[i]] = 0;
		}

		while (!q.empty()) {
			int cx = q.front().first;
			int ctime = q.front().second;
			q.pop();

			for (int i = 0; i < node[cx].size(); i++) {
				int tx = node[cx][i];
				if (check[tx] != -1 && check[tx] < ctime + 1) continue;
				check[tx] = ctime + 1;
				q.push({ tx, ctime + 1 });
			}
		}

		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (check[i] == -1) continue;
			res += 2 * check[i];
		}
			
		if (res < minn) {
			ans = { chic[0], chic[1] };
			minn = res;
		}
		return;
	}
	else {
		for (int i = idx; i <= n; i++) {
			chic.push_back(i);
			bt(i + 1, chic);
			chic.pop_back();
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	vector<int> c;
	bt(1, c);
	printf("%d %d %d\n", ans.first, ans.second, minn);
}