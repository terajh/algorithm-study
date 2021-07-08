#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;
bool compare(char a, char b)
{
    return a > b;
}
int main()
{
    string n;
    cin >> n;
    // 끝이 0 이고 모든 수의 합이 3의 배수

    if (find(n.begin(), n.end(), '0') != n.end())
    {
        int a = 0;
        for (int i = 0; i < n.size(); i++)
        {
            a += n[i] - '0';
        }
        if (a % 3 == 0)
        {
            sort(n.begin(), n.end(), compare);
            cout << n;
        }
        else
        {
            cout << -1;
        }
    }
    else
    {
        cout << -1;
    }
}