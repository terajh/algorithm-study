#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int dp[42][42];
int dir[42][42];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string a, b;
	cin >> a >> b;
	string t1 = "1" + a, t2 = "2" + b;
	
	
	for(int i=1 ; i<=a.size() ; i++) {
		for(int j=1 ; j<=b.size() ; j++) {
			if(a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				dir[i][j] = 2; // 대각 선
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				if(dp[i][j] == dp[i-1][j]) {
					dir[i][j] = 1; // up
				} else {
					dir[i][j] = 3; // left
				}
			}
		}
	}
	
	int i1 = a.size();
	int i2 = b.size();
	string ans;
	while(dir[i1][i2] != 0) {
		if(dir[i1][i2] == 2) {
			ans.push_back(a[i1 - 1]);
			i1--;
			i2--;
		}
		else if(dir[i1][i2] == 1) {
			i1--;
		}
		else if(dir[i1][i2] == 3) {
			i2--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}