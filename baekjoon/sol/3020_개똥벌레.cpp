#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[500010];
int answer = -1, cnt;
int n, h;

int main()
{
    scanf("%d %d", &n, &h);

    for (int i = 0; i < n; i += 1)
    {
        int input;
        scanf("%d", &input);
        if (i % 2 == 0)
        {
            arr[h - input + 1] += 1;
        }
        else
        {
            arr[1] += 1;
            arr[input + 1] -= 1;
        }
    }

    for (int i = 1; i <= h; i++)
    {
        arr[i] += arr[i - 1];
        if (answer == -1 || arr[i] < answer)
        {
            answer = arr[i];
            cnt = 1;
        }
        else if (answer == arr[i])
        {
            cnt += 1;
        }
    }
    printf("%d %d", answer, cnt);

    return 0;
}