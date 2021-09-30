#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

LL input;
LL arr[2001];
LL all_sum[2001];
vector<vector<LL>> v(200001);
vector<vector<LL>> col_sum(200001);

// 입력값이 100만 -> nlogn 으로 끝내야 한다.
int main() {
	int n;
	scanf("%d", &n);

	LL a, b;
	queue<pii> q;
	
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		v[a].push_back(b);
		arr[b] += 1;
		q.push({ a,b });
	}
	
	// 전체 합 구하기
	for (LL i = 1; i <= 2000; i++) 
		all_sum[i] = i * arr[i] + all_sum[i - 1];

	// color 별 합 메모
	for (int i = 1; i <= n; i++) {
		if (v[i].empty()) continue;
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0) {
				col_sum[i].push_back(v[i][j]);
				continue;
			}
			col_sum[i].push_back(col_sum[i].back() + v[i][j]);
		}
	}
	

	pii cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		LL sum = 0;
		int idx = lower_bound(v[cur.first].begin(), v[cur.first].end(), cur.second) - v[cur.first].begin();
		if (idx == 0) 
			sum = 0;
		else 
			sum = col_sum[cur.first][idx - 1];
		LL ans = all_sum[cur.second - 1] - sum;
		printf("%lld\n", (ans < 0) ? 0 : ans);
	}
	
	return 0;
}