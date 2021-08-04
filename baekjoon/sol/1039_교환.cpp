#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int oneChange(int num, int _i, int _j, int _size)
{
    string buf;
    buf = to_string(num);
    if (buf.size() != _size)
    {
        return -1;
    }
    else
    {
        char tp = buf[_i];
        buf[_i] = buf[_j];
        buf[_j] = tp;
        if (buf[0] == '0')
        {
            return -1;
        }
        return stoi(buf);
    }
}

bool visited[11][1000000];
int main(void)
{
    int n, m;
    int _max = -1;
    int cnt = 0;

    cin >> n >> m;

    // size 저장
    string temp = to_string(n);
    int _size = temp.size();

    queue<pair<int, int>> q;
    q.push({n, 0});

    while (!q.empty())
    {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cnt == m)
        {
            _max = max(num, _max);
            continue;
        }
        for (int i = 0; i < _size - 1; i++)
        {
            for (int j = i + 1; j < _size; j++)
            {
                int tn = oneChange(num, i, j, _size);
                if (tn != -1 && visited[cnt][tn] == false)
                {
                    visited[cnt][tn] = true;
                    q.push({tn, cnt + 1});
                }
            }
        }
    }

    cout << _max;
    return 0;
}