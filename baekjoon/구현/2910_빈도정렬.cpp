#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	string val;
	int cnt, idx;
};
bool compare(Node a, Node b) {
	if(a.cnt == b.cnt) {
		return a.idx < b.idx;
	}
	else {
		return a.cnt > b.cnt;
	}
}

Node initNode(string v, int c, int i) {
	Node tp;
	tp.val = v;
	tp.cnt = c;
	tp.idx = i;
	return tp;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n,m, arr[1001];
	
	string input;
	map<string, int> ma;
	// scanf("%d %d", &n, &m);
	cin >> n >> m;
	
	for(int i=1 ; i<=n ; i++) {
		cin >> input;
		if(!ma[input]) {
			ma[input] = i * 10000 + 1;
		}else {
			ma[input] += 1;
		}
	}
	
	vector<Node> v;
	for(map<string,int>::iterator it = ma.begin(); it!= ma.end(); it++) {
		v.push_back(initNode(it->first, (it->second) % 10000, (it->second) / 10000));
	}
	sort(v.begin(), v.end(), compare);
	for(int i=0 ; i<v.size() ; i++) {
		//cout << v[i].val << " " << v[i].cnt << endl;
		int cnt = v[i].cnt;
		string val = v[i].val;
		
		for(int j=0 ; j<cnt ; j++) {
			cout << val << " ";
		}
		
	}
	
	
}