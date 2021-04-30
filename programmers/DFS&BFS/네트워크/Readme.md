# 네트워크

```cpp
bool checkNextNode(int x, int node, int matrixRes) {
    return x != node && matrixRes == 1;
}
vector<int> dfs(vector<vector<int>> net, int node, vector<int> check) {
    int nextNode;
    for (int x = 0; x < net[node].size(); x++) {
        if (checkNextNode(x, node, net[node][x])) {
            nextNode = x;
            if (check[nextNode] == 0) {
                // 체크 안한 노드라면?
                check[nextNode] = 1;
                check = dfs(net, nextNode, check);
            }
        }
    }
    return check;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> check(computers.size(), 0);

    for (int i = 0; i < n; i++) {
        if (check[i] == 0) {
            check[i] = 1;
            answer += 1;
            check = dfs(computers, i, check);
        }
    }

    return answer;
}
```

![https://s3.us-west-2.amazonaws.com/secure.notion-static.com/fa1ddf60-dfe4-4f21-a72a-1f2428c7eb88/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T080030Z&X-Amz-Expires=86400&X-Amz-Signature=6e2789d731a36116cc80e7029ecbf8242ae2dfec8e2091b93d4c037c62b5d763&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/fa1ddf60-dfe4-4f21-a72a-1f2428c7eb88/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T080030Z&X-Amz-Expires=86400&X-Amz-Signature=6e2789d731a36116cc80e7029ecbf8242ae2dfec8e2091b93d4c037c62b5d763&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

---

```cpp
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int check[202];
void dfs(vector<vector<int>> c, int start, int n){
    for(int i=0 ; i<n ; i++){
        if(start == i) continue;
        if(c[start][i] == 1 && check[i] == 0) {
            check[i] = 1;
            dfs(c, i, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(check[i] == 0){
            answer += 1;
            check[i] = 1;
            dfs(computers, i, n);
        }
    }
    return answer;
}
```

![https://s3.us-west-2.amazonaws.com/secure.notion-static.com/2128f2bd-3f82-4fb8-8db7-8560dccd4c25/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T080002Z&X-Amz-Expires=86400&X-Amz-Signature=eefac87257bd70a92c2fa83b88a261a57abc4e1057c01a8075a193ec3bfb6a0d&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/2128f2bd-3f82-4fb8-8db7-8560dccd4c25/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T080002Z&X-Amz-Expires=86400&X-Amz-Signature=eefac87257bd70a92c2fa83b88a261a57abc4e1057c01a8075a193ec3bfb6a0d&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

둘다 dfs 로 풀었는데 약간은 첫 번째 코드가 빠르다.

차이는 check 배열을 전역변수로 두었냐? 차인데

아무래도 전역변수 안 쓰는게 좀 더 빠른 듯 하다.