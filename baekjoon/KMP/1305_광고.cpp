#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>

#define INF 100000000

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
void getPi(vector<int> &pi, string a) {
    int idx = 0;
    int j = 0;
    pi[0] = 0;
    for (int i = 1; i < a.size(); i++) {
        while (j > 0 && a.at(j) != a.at(i)) {
            j = pi[j - 1];
        }
        if (a.at(j) == a.at(i)) {
            pi[i] = j + 1;
            j += 1;
        } 
        else if (j == 0) {
            pi[i] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    string input;
    cin >> n >> input;
    vector<int> ans(n + 1, 0);
    getPi(ans, input);

    // 접미사 빼주면 답이다.
    cout << n - ans[n - 1];
    
    return 0;
}