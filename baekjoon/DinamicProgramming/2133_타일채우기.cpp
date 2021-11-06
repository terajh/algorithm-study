#include <iostream>

using namespace std;

int dp[100];
int main() {
	int n;
	cin >> n;
	// 2의 배수는 2개씩 추가된다.
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 3;
	
	for(int i=4; i<=n ; i+=2) {
		for(int j=2 ; j<=i ; j+=2) {
			if(j == 2) 
				dp[i] += dp[i-j] * 3;
			else if(j != 2)
				dp[i] += dp[i-j] * 2;
		}
		dp[i] += 2;
	}
	cout << dp[n];
}