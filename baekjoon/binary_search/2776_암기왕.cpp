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

int tc, n1, n2, num1[1000001], num2[1000001];

bool bs(int x) {
	int lo = 0, hi = n1;
	int mid;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (num1[mid] == x) {
			return true;
		}
		else if (num1[mid] > x) {
			hi = mid - 1;
		}
		else if (num1[mid] < x) {
			lo = mid + 1;
		}
	}
	return false;
}
int main() {
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		scanf("%d", &n1);
		for (int j = 0; j < n1; j++)
			scanf("%d", &num1[j]);
		sort(num1, num1 + n1);
		scanf("%d", &n2);
		for (int j = 0; j < n2; j++) {
			scanf("%d", &num2[j]);
			int tp = (bs(num2[j])) ? 1 : 0;
			printf("%d\n", tp);
		}
		memset(num1, 0, sizeof(num1));
		memset(num2, 0, sizeof(num2));
	}
	return 0;
}