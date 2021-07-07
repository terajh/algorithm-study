#define _CRT_SECURE_NO_WARNINIGS

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>

using namespace std;

int main() {
	int stu, k;
	cin >> stu>> k;

	map<pair<int, int>, int> map;
	int a, result = 0;
	int b;
	for (int i = 0; i < stu; i++) {
		cin >> a >> b;
		map[{a, b}] += 1;
	}

	for (auto it : map) {
		if (it.second == 0) {
			continue;
		}
		else {
			if (it.second % k == 0) {
				result += it.second / k;
			}
			else {
				result += it.second / k + 1;
			}
		}
	}

	cout << result;
	return 0;
}