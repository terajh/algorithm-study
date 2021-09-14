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
double arr[1001];
int main() {
    int a, res = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a);
        res += a * a;
    }
    printf("%d", res % 10);
    return 0;
}