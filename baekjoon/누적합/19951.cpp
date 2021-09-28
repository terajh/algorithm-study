#include <cstdio>

using namespace std;
typedef long long LL;

int sum[100001];
int arr[100002];
int ground[100002];

int main() {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ground[i]);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr[a] += c;
		arr[b + 1] -= c;
	}

	for (int i = 1; i <= n; i++) 
		sum[i] = sum[i - 1] + arr[i];
	
	for (int i = 1; i <= n; i++) {
		ground[i] += sum[i];
		printf("%d ", ground[i]);
	}
	return 0;
}