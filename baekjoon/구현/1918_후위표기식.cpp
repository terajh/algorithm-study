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

bool check_oper(char c) {
	return (c == '*' || c == '+' || c == '-' || c == '/' || c == '(' || c == ')');
}
bool div_mul(char c) {
	return c == '*' || c == '/';
}
bool plu_min(char c) {
	return c == '+' || c == '-';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string n;
	cin >> n;

	stack<char> st;
	string answer;
	for (int i = 0; i < n.size(); i++) {
		if (check_oper(n.at(i))) {
			if (st.empty()) 
				st.push(n.at(i));
			else {
				if (div_mul(st.top())){
					if (plu_min(n.at(i))) {
						while (1) {
							answer.push_back(st.top());
							st.pop();
							if (st.empty()) break;
							if (plu_min(st.top())) continue;
							else break;
						}
						st.push(n.at(i));
					}
					else if (div_mul(n.at(i))) {
						answer.push_back(st.top());
						st.pop();
						st.push(n.at(i));
					}
					else {
						if (n.at(i) == '(') st.push(n.at(i));
						else if (n.at(i) == ')') {
							while (st.top() != '(') {
								answer.push_back(st.top());
								st.pop();
							}
							st.pop(); // ( 제거
						}
					}
				}
				else if (plu_min(st.top())) {
					if (n.at(i) == ')') {
						while (st.top() != '(') {
							answer.push_back(st.top());
							st.pop();
						}
						if (st.top() == '(') st.pop(); // ( 제거
					}
					else if (plu_min(n.at(i))) {
						answer.push_back(st.top());
						st.pop();
						st.push(n.at(i));
					}
					else {
						st.push(n.at(i));
					}
				}
				else if(st.top() == '(' || st.top() == ')'){
					if (n.at(i) == ')') {
						while (st.top() != '(') {
							answer.push_back(st.top());
							st.pop();
						}
						if(st.top() == '(') st.pop(); // ( 제거
					}
					else st.push(n.at(i));
				}
			}
		}
		// 숫자인 경우
		else {
			answer.push_back(n.at(i));
		}
	}
	while (!st.empty()) {
		answer.push_back(st.top());
		st.pop();
	}
	cout << answer;

	return 0;
}