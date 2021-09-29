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

LL input;
LL sum[1000001];
LL pai[1001];
// 입력값이 100만 -> nlogn 으로 끝내야 한다.
int main() {
	int n;
	LL m;
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &input);
		sum[i] = sum[i - 1] + (input % m);
		sum[i] %= m;
	}
	
	for (int i = 1; i <= n; i++) 
		pai[sum[i]] += 1;
	
	LL res = 0;
	for (LL i = 0; i < m; i++) {
		if (!pai[i]) continue;
		if (i == 0) {
			res += (pai[i] * (pai[i] - 1)) / 2;
			res += pai[i];
		}
		else {
			res += (pai[i] * (pai[i] - 1)) / 2;
		}
	}
	printf("%lld", res);
	return 0;
}