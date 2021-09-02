#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <string.h>
#include <tuple>
#include <set>

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef long long LL;

int n, d, k, c;
int arr[3000001];
int arrkind[3001];


int main() {
	scanf("%d %d %d %d", &n, &d, &k, &c);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	deque<int> dq;
	int cnt = 0, result = 0;

	// 슬라이딩 윈도우!
	for (int i = 0; i < k; i++) {
		dq.push_back(arr[i]);
		if (!arrkind[arr[i]]++)
			cnt += 1;
		result = max(result, cnt);
	}

	for (int i = 0; i < n-1; i++) {
		dq.pop_front();

		if (!(--arrkind[arr[i]]))
			cnt -= 1;
		
		dq.push_back(arr[(i + k) % n]);

		if (!(arrkind[arr[(i + k) % n]])++)
			cnt += 1;

		if (!arrkind[c])
			result = max(result, cnt + 1);
		else
			result = max(result, cnt);
	}
	printf("%d", result);
}