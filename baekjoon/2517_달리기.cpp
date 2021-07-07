#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>


using namespace std;
typedef long long LL;

LL player[500001];
bool isok(int _mid, LL _target) {
    if (player[_mid] < _target) {
        return true;
    }else {
        return false;
    }
}
int main() {
    int player_num;
    scanf("%d", &player_num);
    priority_queue<LL, vector<LL>, less<LL>> pq;
    for (int i = 0; i < player_num; i++) {
        scanf("%lld", &player[i]);

        int left = 0;
        int right = i;
        LL target = player[i];
        int result = 0;

        while(left < right) {
            int mid = (left + right) / 2;
            if(isok(mid, target)) {
                left = mid + 1;
            }else {
                result = mid - 1;
                right = mid - 1;
            }
        }
        printf("%d %d %d\n", result, left, right);
    }
    return 0;
}