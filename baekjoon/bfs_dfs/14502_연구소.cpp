

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <string.h>
#include <tuple>

using namespace std;
typedef pair<int, int> pii;

int arr[9][9];
int check[9][9];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


void checkMem(vector<pii> t, int a, int b, int c, int temp[][9]) {
	temp[t[a].first][t[a].second] = 1;
	temp[t[b].first][t[b].second] = 1;
	temp[t[c].first][t[c].second] = 1;
	return;
}
void unCheckMem(vector<pii> t, int a, int b, int c, int temp[][9]) {
	temp[t[a].first][t[a].second] = 0;
	temp[t[b].first][t[b].second] = 0;
	temp[t[c].first][t[c].second] = 0;
	return;
}
int main() {
	int row, col;
	scanf("%d %d", &row, &col);

	vector<pii> virus;
	vector<pii> space;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)  check[i][j] = 1;
			else if (arr[i][j] == 2) {
				check[i][j] = 1;
				virus.push_back({ i,j });
			}
			else {
				space.push_back({ i,j });
			}
		}
	}

	int tx, ty, _max = 0;

	for (int a = 0; a < space.size(); a++) {
		tx = space[a].first;
		ty = space[a].second;
		if (arr[tx][ty] != 0 || check[tx][ty] == 1) continue;
		for (int b = a + 1; b < space.size(); b++) {
			tx = space[b].first;
			ty = space[b].second;
			if (arr[tx][ty] != 0 || check[tx][ty] == 1) continue;
			for (int c = b + 1; c < space.size(); c++) {
				tx = space[c].first;
				ty = space[c].second;
				if (arr[tx][ty] != 0 || check[tx][ty] == 1) continue;

				
				queue<pii> q;
				for (int i = 0; i < virus.size(); i++) {
					q.push(virus[i]);
				}
				int temp[9][9] = { 0, };
				for (int i = 1; i <= row; i++) 
					for (int j = 1; j <= col; j++) temp[i][j] = check[i][j];
				checkMem(space, a, b, c, temp);
				while (!q.empty()) {
					int tx = q.front().first;
					int ty = q.front().second;
					q.pop();

					for (int i = 0; i < 4; i++) {
						int qx = tx + dx[i];
						int qy = ty + dy[i];
						if (qx < 1 || qy < 1 || qx > row || qy > col) continue;
						if (temp[qx][qy] == 1) continue;
						if (arr[qx][qy] != 0) continue;

						temp[qx][qy] = 1;
						q.push({ qx,qy });
					}
				}
				

				int res = 0;
				for (int i = 1; i <= row; i++) {
					for (int j = 1; j <= col; j++) {
						if (temp[i][j] == 0) res += 1;
					}
				}
				_max = max(_max, res);
			}
		}
	}

	printf("%d\n", _max);

}