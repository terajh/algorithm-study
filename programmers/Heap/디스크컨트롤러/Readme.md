# 디스크 컨트롤러

```cpp
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct compare {
    bool operator()(vector<pair<int, int>> a, vector<pair<int, int>> b) {

    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // 해당 시점에서 최소의 시간을 걸리는 놈을 찎는다. => 그리디

    // jobs => 들어온 시간, 걸리는 시간

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> initQ;
    // start , time 순서로 들어간다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> wQ;
    // time , start 순서로 들어간다.

    for (int i = 0; i < jobs.size(); i++) {
        initQ.push(make_pair(jobs[i][0], jobs[i][1]));
    }

    int currentTime, startTime, workingTime, endTime, waitingTime = 0;

    // 그 다음 2번째 부터 시행 로직
    while (!initQ.empty()) {
        // 일단 맨 처음에 가장 작은 놈 실행
        startTime = initQ.top().first;
        workingTime = initQ.top().second;
        currentTime = startTime;

        wQ.push(make_pair(workingTime, startTime));
        initQ.pop();

        while (!wQ.empty()) {
            workingTime = wQ.top().first; // 프로세스가 일하는 시간
            startTime = wQ.top().second; // 프로세스가 처음 들어온 시간
            endTime = currentTime + workingTime; // 해당 프로세스가 끝나는 시간
            wQ.pop();

            while (!initQ.empty() && endTime >= initQ.top().first) {
                // 현재 끝나는 시간보다 일찍 요청이 들어온게 있는지 모은다
                wQ.push(make_pair(initQ.top().second, initQ.top().first));
                initQ.pop();
            }
            // 결국 wQ 에는 현재 돌릴 수 있는 프로세스가 workingTime 순으로 나열되어있다.

            answer += (endTime - startTime);
            currentTime = endTime;
            printf("start : %d, end : %d, answer : %d\n", startTime, endTime, answer);
        }
    }

    return answer / jobs.size();
}
```

![https://s3.us-west-2.amazonaws.com/secure.notion-static.com/c9636e52-456c-4d11-8939-f044aa4fe4a9/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T111655Z&X-Amz-Expires=86400&X-Amz-Signature=32204683c5f02b45b6d5e0401d086e03a0ac435853c1c9331db743a37e52bb98&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/c9636e52-456c-4d11-8939-f044aa4fe4a9/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T111655Z&X-Amz-Expires=86400&X-Amz-Signature=32204683c5f02b45b6d5e0401d086e03a0ac435853c1c9331db743a37e52bb98&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

queue 를 2개 두고 그 때 그 때 꺼내써야 하기 때문에 맨 위에 해당 시간에 돌릴 수 있는 프로세스를 꺼내는 while 문과 

그 다음 해당 프로세스를 돌린 후 꺼낼 수 있는 프로세스 중에 최소의 workingTime 을 가지는 프로세스를 꺼내는 로직의 그리디 문제이다.

priority_queue 를 여러 개 쓰고 while 문이 3개나 중첩되어 있어 생각하기 힘들지만

실제 프로세스 스케줄링 마냥 생각을 하면 하나하나씩 꺼내야 된다~ 는 로직을 떠올릴 수 있다.