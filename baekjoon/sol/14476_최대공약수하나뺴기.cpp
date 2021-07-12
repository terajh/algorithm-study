#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;
typedef long long LL;
LL arr[1 << 20];
LL up_memo[1 << 20];
LL down_memo[1 << 20];

LL gcd(LL a, LL b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    LL answer = 0;
    LL g;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            g = arr[i];
        else
            g = gcd(g, arr[i]);

        up_memo[i] = g; // i 까지의 up gcd
    }

    for (int i = n; i > 0; i--)
    {
        if (i == n)
            g = arr[i];
        else
            g = gcd(g, arr[i]);
            
        down_memo[i] = g; // i 까지의 down gcd
    }

    int answer_g = 0;
    LL tp_gcd;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            tp_gcd = down_memo[2];
        }
        else if (i == n)
        {
            tp_gcd = up_memo[n - 1];
        }
        else
        {
            tp_gcd = gcd(down_memo[i + 1], up_memo[i - 1]);
        }
        if (answer < tp_gcd)
        {
            answer = tp_gcd;
            answer_g = i;
        }
    }

    if (arr[answer_g] % answer == 0)
    {
        cout << -1;
    }
    else
    {
        cout << answer << " " << arr[answer_g];
    }
}