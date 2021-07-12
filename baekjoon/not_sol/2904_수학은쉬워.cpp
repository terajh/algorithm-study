#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;

int arr[1001];
vector<int> prime;
bool check[1000001];
int counts[100][80000];

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= 1000000; i++)
    {
        if (check[i] == true)
            continue;
        check[i] = true;
        prime.push_back(i);
        int tp = i * 2;
        while (tp <= 1000000)
        {
            check[tp] = true;
            tp += i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        for (int j = 0; j < prime.size(); j++)
        {
            while (num % prime[j] == 0)
            {
                counts[i][j] += 1;
                num /= prime[j];
            }
        }
    }

    vector<pair<int, int>> v;
    // checkPrime 순회해서 마지막 모습 체크
    int resultNum = 1;
    for (int j = 0; j < prime.size(); j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += counts[i][j];
        }
        if (sum / n > 0)
        {
            v.push_back({j, sum / n}); // 최적의 개수 저장
            for (int k = 0; k < sum / n; k++)
            {
                resultNum *= prime[j];
            }
        }
    }

    int result = 0;
    // checkPrime 순회해서 마지막 모습 체킹
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (counts[i][v[j].first] < v[j].second)
            {
                result += v[j].second - counts[i][v[j].first];
            }
        }
    }

    printf("%d %d\n", resultNum, result);
}