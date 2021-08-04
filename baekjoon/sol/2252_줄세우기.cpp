/* 
    위상정렬 문제
    정렬을 위한 배열하다 두고 풀면 된다.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>
#include <math.h>
#include <map>
#include <string.h>

using namespace std;

vector<int> v[32001];
int indegree[32001];

int main()
{
    queue<int> q;
    int n, m, a, b, i;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        indegree[b] += 1;
        v[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i); // 처음 0만 들어간다.
        }
    }

    while (!q.empty())
    {
        i = q.front();
        q.pop();

        printf("%d ", i);
        for (int j = 0; j < v[i].size(); j++)
        {
            indegree[v[i][j]] -= 1;
            if (indegree[v[i][j]] == 0)
                q.push(v[i][j]);
        }
    }
    printf("\n");
    return 0;
}