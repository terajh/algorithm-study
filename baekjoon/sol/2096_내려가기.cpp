#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <set>

using namespace std;

int arr[100000][3];
int maxDp[3];
int minDp[3];
void input(int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
}
int main()
{
    int n;
    input(n);

    // 1. dp 초기화
    for (int i = 0; i < 3; i++)
    {
        maxDp[i] = arr[0][i];
        minDp[i] = arr[0][i];
    }

    // 2. drop-up dp
    for (int i = 1; i < n; i++)
    {

        int dp1 = maxDp[0];
        int dp2 = maxDp[1];
        int dp3 = maxDp[2];

        maxDp[0] = max(arr[i][0] + dp2, arr[i][0] + dp1);
        maxDp[1] = max(arr[i][1] + dp2, arr[i][1] + dp1);
        maxDp[1] = max(maxDp[1], arr[i][1] + dp3);
        maxDp[2] = max(arr[i][2] + dp3, arr[i][2] + dp2);

        int mdp1 = minDp[0];
        int mdp2 = minDp[1];
        int mdp3 = minDp[2];

        minDp[0] = min(arr[i][0] + mdp2, arr[i][0] + mdp1);
        minDp[1] = min(arr[i][1] + mdp2, arr[i][1] + mdp1);
        minDp[1] = min(minDp[1], arr[i][1] + mdp3);
        minDp[2] = min(arr[i][2] + mdp3, arr[i][2] + mdp2);
    }

    int _min = minDp[0];
    int _max = maxDp[0];
    for (int i = 1; i < 3; i++)
    {
        _min = min(minDp[i], _min);
        _max = max(maxDp[i], _max);
    }

    printf("%d %d", _max, _min);
    return 0;
}