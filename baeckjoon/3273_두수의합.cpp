#define _CRT_SECURE_NO_WARNINIGS

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int a;
    cin >> a;

    map<int, int> m;

    int input;
    for (int i = 0; i < a; i++)
    {
        cin >> input;
        m[input] = 1;
    }
    int to;
    cin >> to;

    int result = 0;

    for (auto it : m)
    {
        if (it.first * 2 == to)
            continue;
        if (m[it.first] > 0 && m[to - it.first] > 0)
        {
            result += 1;
            m[it.first] = -1;
            m[to - it.first] = -1;
        }
    }
    cout << result;
}