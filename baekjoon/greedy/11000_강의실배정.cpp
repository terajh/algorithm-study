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

int check[200001];
bool compare(pii a, pii b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, a, b;
	cin >> n;
	vector<pii> cls;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cls.push_back({ a,b });
	}
	sort(cls.begin(), cls.end(), compare);

	vector<int> idx;
	for (int i = 0; i < cls.size(); i++)
		idx.push_back(cls[i].first);

	int res = 0;
	for (int i = 0; i < cls.size(); i++) {
		if (check[i] != 0) continue;
		else check[i] = 1;

		int cx = cls[i].first;
		int cy = cls[i].second;

		while (1) {
			// 제일 맞는 놈 바로 체킹 -> log(n)
			int id = lower_bound(idx.begin(), idx.end(), cy) - idx.begin();
			while (check[id] != 0) 
				id += 1;
			if (id > cls.size() - 1 || cls[id].first < cy) 
				break;
			check[id] = 1;
			cy = cls[id].second;
		}
		res += 1;
	}
	cout << res;
	return 0;
}