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
    string a;
    string b;

    cin >> a;
    cin >> b;

    vector<int> m('z' - 'a' + 1);
    for (char it : a)
        m[it - 'a'] += 1;
    for (char it : b)
        m[it - 'a'] -= 1;

    int result = 0;
    for (auto it : m)
    {
        if (it != 0)
        {
            result += sqrt(it * it);
        }
    }
    cout << result;
}