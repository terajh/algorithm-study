# 더 맵게

```cpp
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
```

![https://s3.us-west-2.amazonaws.com/secure.notion-static.com/c163ba48-7426-4d4e-97e3-a475ffaa0dc9/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T085855Z&X-Amz-Expires=86400&X-Amz-Signature=7316cc501fb883ce45b87c61286361b3b999a41942bca17f9821c656751b3242&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/c163ba48-7426-4d4e-97e3-a475ffaa0dc9/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T085855Z&X-Amz-Expires=86400&X-Amz-Signature=7316cc501fb883ce45b87c61286361b3b999a41942bca17f9821c656751b3242&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

priority_queue 와 같은 min heap 컨테이너를 사용해서 복잡도를 nlogn 으로 낮추되 

섞는 과정에서 적절한 탈출 조건을 주어야 하는 문제이다.