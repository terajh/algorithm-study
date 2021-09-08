#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;


int main() {
    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    cout << max(a, b);
    return 0;
}