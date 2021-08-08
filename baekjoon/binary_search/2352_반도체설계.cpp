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


using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, string> tii;
typedef long long LL;

int n, input;
vector<int> rope;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		rope.push_back(input);
	}

	vector<int> lis;
	for (int i = 0; i < rope.size(); i++) {
		if (lis.empty() || lis.back() < rope[i])
			lis.push_back(rope[i]);
		else if (lis.back() > rope[i]) {
			int idx = lower_bound(lis.begin(), lis.end(), rope[i]) - lis.begin();
			lis[idx] = rope[i];
		}
	}
	cout << lis.size();
	return 0;
}