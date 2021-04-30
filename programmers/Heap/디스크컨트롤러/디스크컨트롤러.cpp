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