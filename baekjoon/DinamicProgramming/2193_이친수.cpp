#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <queue>
#include <vector>

#define rep(i, n) for (i = 1; i <= n; i++)

using namespace std;
typedef long long LL;
int arr[100001];
LL dp[100001][2];

void input(int &a)
{
    scanf("%d", &a);
}
void output(int a)
{
    printf("%d\n", a);
}
int main()
{
    int n, k, i;

    input(n);

    dp[1][1] = 1;
    dp[1][0] = 0;
    dp[2][1] = 0;
    dp[2][0] = 1;
    dp[3][1] = 1;
    dp[3][0] = 1;
    if (n > 3)
    {
        for (int i = 4; i <= n; i++)
        {
            // 끝이 1으로 끝나는 이친수에 더하기
            dp[i][1] = dp[i - 1][0];

            // 끝이 0으로 끝나는 이친수
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        }
    }

    printf("%lld\n", dp[n][0] + dp[n][1]);
}