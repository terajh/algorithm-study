#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string.h>

int arr[12][12];
int check[12];
int maxn = 0;
using namespace std;
void dfs(int x, int cnt, int sum) {
	if(cnt == 11) {
		maxn = max(maxn, sum);
		return;
	}
	
	for(int i=1 ; i<=11 ; i++) {
		if(arr[x+1][i] == 0) continue;
		if(check[i]) continue;
		
		check[i] = 1;
		dfs(x+1, cnt+1, sum+arr[x+1][i]);
		check[i] = 0;
	}
}
int main() {
	int tc;
	scanf("%d", &tc);
	
	for(int t=0 ; t < tc ; t++) {
		for(int i = 1 ; i<= 11 ; i++) {
			for(int j=1 ; j<=11 ; j++) {
				scanf("%d" , &arr[i][j]);
			}
		}
		
		memset(check, 0, sizeof(check));
		dfs(0, 0, 0);
		
		printf("%d\n", maxn);
		maxn = 0;
	}
}