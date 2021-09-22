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
int arr[100001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	vector<int> ans(2);
	int minn = 2147483647, calc;
	
	for (int lo = 0, hi = n-1; lo < hi; ) {
		calc = arr[lo] + arr[hi];
		if (calc < 0) {
			if (abs(calc) <= minn) {
				minn = abs(calc);
				ans[0] = arr[lo];
				ans[1] = arr[hi];
				lo++;
			}
			else {
				lo++;
			}
		}
		else {
			if (abs(calc) <= minn) {
				minn = abs(calc);
				ans[0] = arr[lo];
				ans[1] = arr[hi];
				hi--;
			}
			else {
				hi--;
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}