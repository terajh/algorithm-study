#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <string.h>
#include <tuple>

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef long long LL;


int tc, a, b, c;
vector<vector<pii>> tree(100001);
int check[100001];

struct Node {
	int v, w;
};
struct Compare {
	bool operator()(pii a, pii b) {
		return a.second > b.second;
	}
};

int end_point;
LL r = 0;

void dfs(int from, LL w) {
	check[from] = 1;
	if (r < w) {
		r = w;
		end_point = from;
	}
	for (int i = 0; i < tree[from].size(); i++) {
		pii tp = tree[from][i];
		if (check[tp.first] == 0) {
			check[tp.first] = 1;
			dfs(tp.first, tp.second + w);
		}
	}
}
int main() {
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		b = 0;
		scanf("%d", &a);
		while (1) {
			scanf("%d", &b);
			if (b == -1) break;
			else {
				scanf("%d", &c);
				tree[a].push_back({ b,c });
				tree[b].push_back({ a,c });
			}
		}
	}
	dfs(1, 0);
	r = 0;
	memset(check, 0, sizeof(check));
	dfs(end_point, 0);

	printf("%lld\n", r);
}