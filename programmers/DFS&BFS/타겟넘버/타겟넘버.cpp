#include <string>
#include <vector>
#include <iostream>

using namespace std;
int _count = 0;
void dfs(vector<int> check, vector<int> num, int target, int current, int idx, int _size) {
    if (target == current && _size == num.size()) {
        _count += 1;
        return;
    }

    for (int i = idx; i < num.size(); i++) {
        if (check[i] == 0) {
            check[i] = 1;
            dfs(check, num, target, current + num[i], i+1, _size + 1);
            dfs(check, num, target, current - num[i], i+1, _size + 1);
            check[i] = 0;
        }
    }
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> check(numbers.size(), 0);
    // dfs 정석 대로
    dfs(check, numbers, target, 0, 0, 0);

    cout << _count << endl;
    return _count;
}