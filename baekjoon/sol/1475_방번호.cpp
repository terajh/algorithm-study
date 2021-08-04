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
    string n;

    cin >> n;
    int result = 0;
    map<char, int> m;
    for (auto it : n)
    {
        m[it] += 1;
    }

    if ((m['9'] + m['6']) % 2 == 0)
    {
        m['9'] = (m['9'] + m['6']) / 2;
    }
    else
    {
        m['9'] = (m['9'] + m['6']) / 2 + 1;
    }
    m['6'] = 0;
    int _max = 0;
    for (auto it : m)
    {
        _max = max(it.second, _max);
    }
    cout << _max;
}