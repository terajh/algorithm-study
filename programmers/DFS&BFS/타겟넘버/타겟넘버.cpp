#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>

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

void bfs(vector<int> check, vector<int> num, int target) {
    queue<tuple<int, int, int>> q; // idx, neg
    q.push(make_tuple(0, 1, num[0]*1));
    q.push(make_tuple(0, -1, num[0] * (-1)));
    check[0] = 1;

    int idx, neg;
    int sum = 0;


    while (!q.empty()) {
        
        idx = get<0>(q.front());
        neg = get<1>(q.front());
        sum = get<2>(q.front());
        q.pop();

        if (target == sum && idx == num.size() - 1) {
            _count += 1;
            continue;
        }
        else if (idx >= num.size() -1) {
            continue;
        }
        else {
            q.push(make_tuple(idx + 1, 1, sum + num[idx + 1] * 1));
            q.push(make_tuple(idx + 1, -1, sum + num[idx + 1] * (-1)));
            continue;
        }
    }
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> check(numbers.size(), 0);
    // dfs(check, numbers, target, 0, 0, 0);
    bfs(check, numbers, target);
    cout << _count << endl;
    return _count;
}