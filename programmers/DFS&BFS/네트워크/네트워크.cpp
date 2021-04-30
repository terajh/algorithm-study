#include <string>
#include <vector>
#include <iostream>

using namespace std;

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
                // 기존 dfs 와는 다르게 여기서 check를 닫지 않는다. 계속 체크해야 하기 때문에
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