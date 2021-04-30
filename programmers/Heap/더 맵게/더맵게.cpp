#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int first, second;
    while(!pq.empty()) {
        // 탈출 조건
        if(pq.size() == 1) {
            if(pq.top() < K) answer = -1;
            break;
        }
        if(pq.top() > K) break;
        
        first = pq.top(); pq.pop();
        second = pq.top(); pq.pop();
        // 섞기
        answer += 1;
        pq.push(first + second*2);
        
    }
    return answer;
}