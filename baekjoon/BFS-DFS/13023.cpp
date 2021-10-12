#include <cstdio>
#include <vector>

using namespace std;
vector<vector<int>> peo;
int check[2001];
bool isOk;
void dfs(int x, int cnt) {
    if(isOk) return;
    if(cnt == 5) {
        isOk = true;
        return;
    }
    for(int i=0 ; i<peo[x].size() ; i++) {
        if(check[peo[x][i]] || isOk) continue;
        check[peo[x][i]] = 1;
        dfs(peo[x][i], cnt+1);
        check[peo[x][i]] = 0;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a, b;
    peo = vector<vector<int>>(n);

    for(int i=0 ; i<m ; i++) {
        scanf("%d %d", &a, &b);
        peo[a].push_back(b);
        peo[b].push_back(a);
    }

    for(int i=0 ; i<n ; i++) {
        check[i] = 1;
        dfs(i, 1);
        check[i] = 0;
    }
    printf("%d\n", (isOk) ? 1 : 0);
    return 0;
}