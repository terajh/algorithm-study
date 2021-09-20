#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

#define MAX_INT 1000000000
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;
int arr[81];
int score(string a) {
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < a.size(); i++) {
        if (a.at(i) == 'O') {
            if (i == 0) arr[i] = 1;
            else {
                arr[i] = arr[i - 1] + 1;
            }
        }
        else {
            arr[i] = 0;
        }
    }
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        res += arr[i];
    }

    return res;
}
int main() {
    priority_queue<pii> pq;
    string in;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> in;
        printf("%d\n", score(in));
    }
    return 0;
}