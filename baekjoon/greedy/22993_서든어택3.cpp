#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
LL fst, input;
deque<LL> dq;
bool check[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n >> fst;
    for (int i = 0; i < n - 1; i++) {
        cin >> input;
        dq.push_back(input);
    }
    sort(dq.begin(), dq.end());
    while (!dq.empty()) {
        if (dq.front() >= fst) 
            break;
        else if (dq.front() < fst) {
            fst += dq.front();
            dq.pop_front();
        }
    }
    if (dq.empty()) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}