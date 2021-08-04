
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

int stud[1002];
int pic_frame[1002];

struct node
{
    int counts;
    int stu;
    int time;
};
int getIdx()
{
    int _min = 10000;
    int _minIdx;
    for (int j = 0; j < 1002; j++)
    {
        if (pic_frame[j] != 0)
        {
            if (_min > stud[j])
            {
                _min = stud[j];
                _minIdx = j;
            }
            else if (_min == stud[j])
            {
                if (pic_frame[_minIdx] > pic_frame[j])
                {
                    _min = stud[j];
                    _minIdx = j;
                }
            }
        }
    }
    return _minIdx;
}
int main()
{
    int n;
    int k;
    int studentCounts = 0;
    cin >> n;
    cin >> k;

    vector<node> v;
    for (int i = 0; i < k; i++)
    {
        int students;
        cin >> students;
        stud[students] += 1;

        if (studentCounts == n)
        { // 꽉 차 있는 경우
            // 빼야함
            if (pic_frame[students] != 0)
            {
                continue;
            }
            else
            {
                int selIdx = getIdx();
                pic_frame[selIdx] = 0;
                pic_frame[students] = i;
                stud[selIdx] = 0;
            }
        }
        else
        { // 바로 들어갈 수 있다.
            if (pic_frame[students] == 0)
            {
                studentCounts += 1;
                pic_frame[students] = i + 1;
            }
        }
    }
    for (int i = 0; i < 1002; i++)
    {
        if (pic_frame[i] != 0)
        {
            printf("%d ", i);
        }
    }

    return 0;
}