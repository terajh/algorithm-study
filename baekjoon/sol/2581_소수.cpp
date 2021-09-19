#include <iostream>
#include <algorithm>

using namespace std;

bool check[10001];
bool prime[10001];
int main() {
    int a, b;
    cin >> a >> b;

    for(int i=2 ; i<=b ; i++) {
        if(check[i]) continue;
        prime[i] = true;
        for(int j=i+i ; j<=b ; j+= i) {
            check[j] = true;
        }
    }

    long long res = 0;
    long long min_ = 10001;
    for(long long i=a ; i<=b ; i++) {
        if(prime[i]) {
            res += i;
            min_ = min(min_, i);
        }
    }
    if(res == 0) cout << -1;
    else cout << res << "\n" << min_;

    return 0;
}