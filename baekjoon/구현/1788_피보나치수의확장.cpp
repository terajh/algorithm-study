#include <iostream>
#include <cmath>

#define MAX 1000000000
using namespace std;


int dp[1000001];
int main() {
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2 ; i<=abs(n) ; i++) {
		dp[i] = (dp[i-1] + dp[i-2])%MAX;
	}
	// 1 0 1(-1) -1(-2) 2(-3) -3 5 -8 ... 
	
	if(n < 0) {
		if(abs(n) % 2 == 0) {
			cout << -1 << endl;	
		} 
		else if(abs(n) % 2 != 0) {
			cout << 1 << endl;
		}
	} else if( n == 0){
		cout << 0 << endl;
	}else {
		cout << 1 << endl;
	}
	
	cout << dp[abs(n)];
}