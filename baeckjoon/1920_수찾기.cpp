#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int aArr[100001];
int bArr[100001];
int n, m;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> aArr[i];
    sort(aArr, aArr + n);
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> bArr[i];
}

bool binarySearch(int idx)
{
    int target = bArr[idx];

    int left = 0;
    int right = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (aArr[mid] == target)
        {
            return true;
        }
        else if (aArr[mid] < target)
            left = mid + 1;
        else if (aArr[mid] > target)
            right = mid - 1;
    }
    return false;
}
void solution()
{
    for (int i = 0; i < m; i++)
    {
        if (binarySearch(i))
            printf("%d\n", 1);
        else
            printf("%d\n", 0);
    }
    return;
}
int main()
{
    input();
    solution();

    return 0;
}