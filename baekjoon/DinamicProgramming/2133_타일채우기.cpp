#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[31];
int main() {
    int n;
    cin >> n;
    
    dp[1] = 0;
    dp[2] = 3;

    for(int i=3 ; i<=n ; i++) {
        if(dp[i-2]!=0) dp[i] = dp[i-2] + 3;
    }
    cout << dp[n];
}