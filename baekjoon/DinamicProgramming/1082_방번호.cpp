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
string dp[200];

string convert(string a) {
	string res;
	if (a == "") return "";
	for (int i = 0; i < a.size(); i++) {
		if (a.at(i) == '0') continue;
		else {
			res = a.substr(i);
			break;
		}
	}
	if (res == "") return "0";
	else return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, input, money;
	vector<int> v;
	int _min = 50;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
		_min = min(_min, input);
	}
	cin >> money;

	for (int i = _min; i <= money; i++) {
		for (int j = 0; j < n; j++) {
			if (i - v[j] < 0) continue;
			for (int k = 0; k < dp[i - v[j]].size(); k++) {
				if (dp[i - v[j]][k] - '0' >= j) continue;
				string new_str = convert(dp[i - v[j]].substr(0, k) + to_string(j) + dp[i - v[j]].substr(k + 1));
				// cout << new_str << endl;
				if (dp[i].size() < new_str.size()) {
					dp[i] = new_str;
				}
				else if (dp[i].size() == new_str.size()) {
					dp[i] = max(dp[i], new_str);
				}
			}
			if (dp[i - v[j]].empty() && j == 0)
				continue;

			string t = dp[i - v[j]] + to_string(j);
			if (dp[i].length() < t.length())
				dp[i] = t;
			else if (dp[i].length() == t.length())
				dp[i] = max(dp[i], t);
		}
	}

	if (dp[money].empty()) cout << 0;
	else {
		cout << dp[money];
	}
	return 0;
}