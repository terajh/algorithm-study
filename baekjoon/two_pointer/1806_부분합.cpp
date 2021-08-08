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
LL arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = n + 10;
	for (int lo = 0, hi = 0; lo <= hi && hi < n && lo < n; ) {
		LL res = 0;
		for (int k = lo; k <= hi; k++) {
			res += arr[k];
		}
		if (res >= s) ans = min(ans, hi - lo++ + 1);
		else hi++;
	}

	if (ans == n + 10) cout << 0;
	else cout << ans;

	return 0;
}