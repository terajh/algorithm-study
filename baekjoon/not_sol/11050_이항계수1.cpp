#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int res = 1;
    for (int i = 0; i < k; i++)
    {
        res *= (n - i);
    }
    for (int i = 0; i < k; i++)
    {
        res /= (k - i);
    }
    printf("%d", res);
}