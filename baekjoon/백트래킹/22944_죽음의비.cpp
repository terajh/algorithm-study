#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_INT 100000000
using namespace std;

typedef pair<int, int> pii;
int n, h, d;
vector<string> v;
vector<pii> umbrella;
int umbcheck[11];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
struct Node {
	int x, y, dis, hp, umb;
};
Node initNode(int x, int y, int dis, int hp, int umb) {
	Node tp;
	tp.x = x;
	tp.y = y;
	tp.dis = dis;
	tp.hp = hp;
	tp.umb = umb;
	return tp;
}
pii startPos;
pii endPos;
int minn = MAX_INT;
pii getHpUmb(int dist, int hp, int umb) {
	while (dist > 0) {
		if (umb > 0) {
			dist -= 1;
			umb -= 1;
		}
		else {
			dist -= 1;
			hp -= 1;
		}
	}
	return { hp, umb };
}
void bt(int x, int y, int hp, int umb, int cnt) {

	int cx = x;
	int cy = y;
	int cdist = cnt;
	int cumb = umb;
	int chp = hp;
	if (endPos.first == cx && endPos.second == cy) {
		minn = min(minn, cdist);
		return;
	}
	// 여기서 목적지까지 가지 못하면 주변 umb 하나 체킹한다.
	if (abs(endPos.first - cx) + abs(endPos.second - cy) > cumb + chp) {
		for (int i = 0; i < umbrella.size(); i++) {
			int tx = umbrella[i].first;
			int ty = umbrella[i].second;
			int tdist = abs(tx - cx) + abs(ty - cy);
			if (umbcheck[i]) continue;
			if (tdist > cumb + chp) continue;

			umbcheck[i] = 1;
			pii hpUmb = getHpUmb(tdist, chp, cumb);
			bt(tx, ty, hpUmb.first, d, cdist + tdist);
			umbcheck[i] = 0;
		}
	}
	// 목적지까지 갈 수 있으면!!
	else {
		minn = min(minn, cdist + abs(endPos.first - cx) + abs(endPos.second - cy));
		return;
	}
}

int main() {
	scanf("%d %d %d", &n, &h, &d);

	string tp;
	for (int i = 0; i < n; i++) {
		cin >> tp;
		v.push_back(tp);
		for (int j = 0; j < tp.size(); j++) {
			if (tp[j] == 'S') startPos = { i,j };
			else if (tp[j] == 'E') endPos = { i,j };
			else if (tp[j] == 'U') umbrella.push_back({ i,j });
		}
	}
	bt(startPos.first, startPos.second, h, 0, 0);
	// printf("%d\n", (check[endPos.first][endPos.second] == 0) ? -1 : check[endPos.first][endPos.second]);
	printf("%d\n", (minn == MAX_INT) ? -1 : minn);
}