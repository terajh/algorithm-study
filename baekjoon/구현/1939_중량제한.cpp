#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int check[100001];
int start, finished;
vector<pii> v[100001];

bool bfs(int cost) {
	queue<int> q;
	q.push(start);
	check[start] = 1;
	
	while(!q.empty()) {
		int cx = q.front();
		q.pop();
		
		if(cx == finished) {
			return true;
		}
		
		for(int i=0 ; i<v[cx].size() ; i++) {
			int tx = v[cx][i].first;
			int tval = v[cx][i].second;
			if(check[tx]) continue;
			if(cost > tval) continue;
			
			check[tx] = 1;
			q.push(tx);
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	int a, b, c, cmax = 0;
	
	for(int i=1 ; i<=m ; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
		cmax = max(cmax, c);
	}
	cin >> start >> finished;
	int left = 0, right = cmax, mid;
	int nmax = 0;
	while(left <= right) {
		
		mid = (left + right) / 2;
		memset(check, 0, sizeof(check));
		if(bfs(mid)) {
			left = mid + 1;
			nmax = max(nmax, mid);
		}
		else {
			right = mid - 1;
		}
	}
	cout << nmax;
}