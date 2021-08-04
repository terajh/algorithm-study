#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int a, b;
    int c, d;
    cin >> a >> b;
    cin >> c >> d;

    int res_b = b * d;
    int res_a = a * d + c * b;

    int g = gcd(res_a, res_b);

    cout << res_a / g << " " << res_b / g;
    return 0;
}