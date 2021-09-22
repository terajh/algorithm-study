#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;
typedef long long LL;

LL arr[5001];
int main() {
	LL n;
	scanf("%lld", &n);

	for (LL i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	vector<LL> ans(3);
	LL minn = 21474836470, calc, mid;
	for (LL a = 0; a < n; a++) {
		mid = arr[a];
		for (LL lo = a + 1, hi = n - 1; lo < hi; ) {
			calc = arr[lo] + arr[hi] + arr[a];
			if (abs(calc) <= minn) {
				minn = abs(calc);
				ans[0] = arr[lo];
				ans[1] = arr[hi];
				ans[2] = mid;
			}
			if (calc < 0) {
				lo++;
			}
			else {
				hi--;
			}
		}
	}
	
	sort(ans.begin(), ans.end());
	printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
	return 0;
}