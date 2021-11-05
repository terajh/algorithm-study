#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pii;
vector<pii> v;
int arr[205];
int main() {
	int n;
	cin >> n;
	int a, b;
	for(int i=0 ; i<n ; i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	for(int i=0 ; i<v.size() ; i++) {
		for(int j=0 ; j<v.size() ; j++) {
			if(i == j) continue;
			if(v[i].first > v[j].first && v[i].second > v[j].second) {
				arr[j] += 1;
			}
		}
	}
	
	
	for(int i=0 ; i<v.size() ; i++) {
		cout << arr[i]+1 << " ";
	}
}