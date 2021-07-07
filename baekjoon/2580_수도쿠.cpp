#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int board[10][10];
int box[4][4][10];
int row[10][10];
int col[10][10];
bool isok = false;
vector<pair<int, int>> hole;

void input()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                hole.push_back({i, j});
            else
            {
                box[(i - 1) / 3][(j - 1) / 3][board[i][j]] = 1; // box memo
                row[i][board[i][j]] = 1;                        // 가로 memo
                col[j][board[i][j]] = 1;                        // 세로 memo
            }
        }
    }
}

vector<int> getNum(int a, int b)
{
    vector<int> t(10, 0);
    vector<int> output;
    for (int i = 1; i < 10; i++)
    {
        if (t[i] == 0)
            output.push_back(i);
    }
    return output;
}

void printArr()
{
    printf("\n");
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void dfs(int pos)
{
    if (isok)
        return;
    if (pos >= hole.size())
    {
        printArr();
        isok = true;
        return;
    }
    int x = hole[pos].first;
    int y = hole[pos].second;
    for (int i = 1; i <= 9; i++)
    {

        // 1. 직사각형 통과
        int tx = (x - 1) / 3;
        int ty = (y - 1) / 3;
        if (box[tx][ty][i] == 1)
            continue;

        // 2. 가로줄 통과
        if (row[x][i] == 1)
            continue;

        // 3. 세로줄 통과
        if (col[y][i] == 1)
            continue;

        // 4. 다 통과했으면 memo 하고 dfs 순회
        box[tx][ty][i] = 1;
        row[x][i] = 1;
        col[y][i] = 1;
        board[x][y] = i;
        dfs(pos + 1);
        board[x][y] = 0;
        box[tx][ty][i] = 0;
        row[x][i] = 0;
        col[y][i] = 0;
    }
}

void solution()
{
    dfs(0);
}
int main()
{
    input();
    solution();

    return 0;
}