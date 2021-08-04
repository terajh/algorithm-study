#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;
bool check[100000000];
vector<int> prime;

int main()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            int tp = i;
            while (tp <= n)
            {
                tp += i;
                check[tp] = true;
            }
            prime.push_back(i);
        }
    }

    for (int i = 0; i < prime.size(); i++)
    {
        while (n % prime[i] == 0)
        {
            cout << prime[i] << endl;
            n /= prime[i];
        }
    }
}