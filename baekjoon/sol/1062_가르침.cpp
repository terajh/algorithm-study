
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

int arr[26];
int mask[51][26];
int check[26];
int use[26];
int n, k;
int _max = 0;

int counts()
{ 
    int _counts = 0;
    for (int k = 0; k < n; k++)
    {
        bool checks = true;
        for (int i = 0; i < 26; i++)
        {
            if (mask[k][i] == 1 && check[i] == 0)
            {
                checks = false;
                break;
            }
        }
        if (checks)
            _counts += 1;
    }
    return _counts;
}
void dfs(int c, int w)
{
    if (w >= k - 5)
    {
        _max = max(counts(), _max);
        return;
    }
    for (int i = c; i < 26; i++)
    {
        if (i == 'a' - 'a' || i == 'c' - 'a' || i == 'i' - 'a' || i == 't' - 'a' || i == 'n' - 'a')
            continue;
        if (i == 'z' - 'a' && use[i] == 0)
        {
            _max = max(counts(), _max);
            continue;
        }
        check[i] = 1;
        dfs(i + 1, w + 1);
        check[i] = 0;
    }
}
int main()
{
    cin >> n >> k;
    check['a' - 'a'] = 1;
    check['n' - 'a'] = 1;
    check['t' - 'a'] = 1;
    check['i' - 'a'] = 1;
    check['c' - 'a'] = 1;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < input.size(); j++)
        {
            mask[i][input[j] - 'a'] = 1;
            use[input[j] - 'a'] = 1;
        }
    }

    if (k < 5)
        cout << 0;
    else if (k == 26)
        cout << n;
    else
    {
        dfs(0, 0);
        cout << _max;
    }
    return 0;
}