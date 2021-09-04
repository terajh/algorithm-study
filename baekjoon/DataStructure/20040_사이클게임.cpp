#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <tuple>
#include <string>
#include <string.h>
#include <stack>
#include <set>
#include <map>


using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef tuple<int, int, string> tii;
int root[500001];
int find_union(int a) {
	if (root[a] == a)
		return a;
	else {
		return find_union(root[a]);
	}
}
bool set_union(int a, int b) {
	int x = find_union(a);
	int y = find_union(b);
	if (x == y) return false;
	if (x < y) root[y] = x;
	else root[x] = y;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, a, b;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		root[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (!set_union(a, b)) {
			cout << i;
			break;
		}
		if (i == m) {
			cout << 0; 
			break;
		}
	}

	return 0;
}