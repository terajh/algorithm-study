#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, input;
	deque<int> dq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		dq.push_back(input);
	}
	
	int check[1001] = { 0, };
	int cnt = 2, cx, cidx = 0;
	check[0] = 1;
	cout << 1 << " ";
	for(int i=2 ; i<=n ; i++){
		cx = dq[cidx];
		// cidx 풍선 터뜨림

		int ct = 0;
		if (cx < 0) {
			while (ct < -1 * cx) {
				cidx = (cidx == 0) ? n - 1 : cidx - 1;
				if (check[cidx] != 0) continue;
				else ct++;
			}
		}
		else {
			while (ct < cx) {
				cidx = (cidx == n - 1) ? 0 : cidx + 1;
				if (check[cidx] != 0) continue;
				else ct++;
			}
		}
		check[cidx] = i;
		cout << cidx+1 << " ";
	}

	return 0;
}