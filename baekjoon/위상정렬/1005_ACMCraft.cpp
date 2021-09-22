#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;
int arr[1001];
int innum[1001];
int sum[1001];
int main() {
	int tc, n, k, a, b;
	int target;
	vector<vector<int>> v;
	scanf("%d", &tc);
	for (int t = 0; t< tc; t++) {
		
		scanf("%d %d", &n, &k);
		
		for (int j = 1; j <= n; j++) {
			arr[j] = 0;
			sum[j] = 0;
			v[j].clear();
		}

		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[j]);
		}
		for (int j = 0; j < k; j++) {
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			innum[b] += 1;
		}


		queue<int> q;
		for (int j = 1; j <= n; j++) {
			if (innum[j] == 0) {
				q.push(j);
				sum[j] = arr[j];
			}
		}
		while (!q.empty()) {
			int tx = q.front();
			for (int i = 0; i < v[tx].size(); i++) {
				sum[v[tx][i]] = max(sum[v[tx][i]], sum[tx] + arr[v[tx][i]]);
				innum[v[tx][i]] -= 1;
				if (innum[v[tx][i]] == 0) q.push(v[tx][i]);
			}
			q.pop();
		}
		scanf("%d", &target);
		printf("%d\n", sum[target]);
	}
	return 0;
}