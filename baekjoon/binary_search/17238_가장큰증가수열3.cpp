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
typedef long long LL;
typedef pair<LL, LL> pii;
typedef tuple<int, int, string> tii;

LL n, s;
LL arr[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	vector<LL> lis;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (lis.empty() || lis.back() < arr[i])
			lis.push_back(arr[i]);
		else if (lis.back() > arr[i]) {
			int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[idx] = arr[i];
		}
	}
	cout << lis.size();

	return 0;
}