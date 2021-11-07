#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int arr[200000];
int check[100002];

struct compare {
    bool operator()(pii a, pii b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};
vector<vector<int>> v;
priority_queue<pii, vector<pii>, compare> pq;
void dfs(int x, vector<int> &buf) {
    if (check[x]) {
        return;
    }
    check[x] = 1;
    for (int i = 0; i < v[x].size(); i++) {
        buf.push_back(v[x][i]);
        dfs(v[x][i], buf);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n, input;
    cin >> n;
    v = vector<vector<int>>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> input;
        v[i].push_back(input);
        arr[input] += 1;
    }

    vector<int> tp;
    dfs(1, tp);
    for (int i = 1; i <= n; i++) {
        pq.push({ arr[i], i });
    }

    while (!pq.empty()) {
        int cval = pq.top().first;
        int cidx = pq.top().second;
        pq.pop();

        if (check[cidx]) continue;
        tp.push_back(cidx);
        dfs(cidx, tp);
    }

    cout << tp.size() << endl;
    for (int i = 0; i < tp.size(); i++) {
        cout << tp[i] << " ";
    }
}