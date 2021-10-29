#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int check[101];
vector<int> prime;
int m, seed, x1, x2;
bool isok = false;

void bt(int idx, vector<int>& buf) {
    if (isok) return;
    if (buf.size() == 2) {
        int tx1 = (buf[0] * seed + buf[1]) % m;
        if (tx1 != x1) return;
        int tx2 = (buf[0] * x1 + buf[1]) % m;
        if (tx2 != x2) return;
        isok = true;
        cout << buf[0] << " " << buf[1] << "\n";
        return;
    }
    for (int i = idx; i <= m; i++) {
        buf.push_back(i);
        bt(idx + 1, buf);
        buf.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> m >> seed >> x1 >> x2;

    for (int i = 2; i <= m; i++) {
        if (check[i]) continue;
        for (int j = i; j <= m; j += i) {
            check[j] = 1;
        }
        prime.push_back(i);
    }

    vector<int> buf;
    bt(0, buf);
    return 0;

}