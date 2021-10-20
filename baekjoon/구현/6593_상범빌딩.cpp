#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

char arr[40][40][40];
int check[40][40][40];

struct Node {
	int x, y, z;
	int time;
};

Node initNode(int x, int y, int z, int t) {
	Node tp;
	tp.x = x;
	tp.y = y;
	tp.z = z;
	tp.time = t;
	return tp;
}

int dx[] = {-1, 0, 1, 0 ,0, 0 };
int dy[] = {0, -1, 0 ,1 , 0 ,0 };
int dz[] = {0, 0, 0, 0, 1, -1};

int main() {
	
	int n, m, l;
	while(1) {
		memset(arr, 0, sizeof(arr));
		memset(check, 0, sizeof(check));
		scanf("%d %d %d", &n, &m, &l);
		if(!n && !m && !l) break;
		int sx, sy, sz;
		for(int x=1 ; x<=n; x++) {
			for(int y=1 ; y<=m; y++) {
				for(int z=1 ; z<=l ; z++) {
					scanf(" %1c", &arr[x][y][z]);
					if(arr[x][y][z] == 'S') {
						sx = x; sy = y; sz = z;
					}
				}
			}
		}
		queue<Node> q;
		q.push(initNode(sx, sy, sz, 0));
		check[sx][sy][sz] = 1;
		int maxn = 0;
		while(!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			int cz = q.front().z;
			int ctime = q.front().time;
			q.pop();
			if(arr[cx][cy][cz] == 'E') {
				maxn = max(maxn, ctime);
				continue;
			}
			for(int i=0 ; i<6 ;i++) {
				int tx = cx + dx[i];
				int ty = cy + dy[i];
				int tz = cz + dz[i];
				
				if(tx < 1 || tx > n) continue;
				if(ty < 1 || ty > m) continue;
				if(tz < 1 || tz > l) continue;
				if(arr[tx][ty][tz] == '#') continue;
				if(check[tx][ty][tz]) continue;
				check[tx][ty][tz] = 1;
				q.push(initNode(tx, ty, tz, ctime + 1));
			}
		}
		if(maxn == 0) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << maxn<< " minute(s).\n";
		}
		
	}
	
	return 0;
}