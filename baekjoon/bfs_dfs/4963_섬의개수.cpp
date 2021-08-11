

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

int arr[51][51];
int check[51][51];
int dx[8] = { 0,1,0,-1, 1, 1, -1 ,-1};
int dy[8] = { 1,0,-1,0 ,1, -1, 1, -1};

int main() {
	int w, h;

	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		int res = 0;
		memset(check, 0, sizeof(check));
		queue<pii> q;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (arr[i][j] == 1 && check[i][j] == 0) {
					check[i][j] = 1;
					q.push({ i,j });
					while (!q.empty()) {
						int tx = q.front().first;
						int ty = q.front().second;
						q.pop();

						for (int i = 0; i < 8; i++) {
							int qx = tx + dx[i];
							int qy = ty + dy[i];
							if (qx < 1 || qy < 1 || qx > h || qy > w) continue;
							if (check[qx][qy] != 0 || arr[qx][qy] != 1) continue;
							check[qx][qy] = 1;
							q.push({ qx,qy });
						}
					}
					res += 1;
				}
			}
		}
		printf("%d\n",res);

	}

}