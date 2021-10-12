#include <cstdio>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m;
int arr[1001];

int main() {
	int input;
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++) {
		scanf("%d", &m);
		memset(arr, 0, sizeof(arr));
		for(int j=1 ; j<=m ; j++) {
			scanf("%d", &input);
			arr[j] = arr[j-1] + input;
		}
		
		int maxn = -1000000;
		
		for(int j=0; j<=m ; j++) {
			for(int k=j+1 ; k<=m ; k++) {
				maxn = max(maxn, arr[k] - arr[j]);
			}
		}
		printf("%d\n", maxn);
	}
	
	
}