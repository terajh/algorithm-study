#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    
    unsigned long long right = *max_element(times.begin(), times.end()) * n;
    // 최대값을 right 로 설정
    unsigned long long left = 1;
    // 최소값을 left 로 설정
    
    while(left <= right) {
        unsigned long long mid = (right + left) / 2;
        unsigned long long sum = 0;
        
        for(int i = 0; i < times.size() ; i++) {
            sum += mid / times[i];
        }
        // 시간이 mid 만큼 걸렸을 때, 얼마만큼의 사람을 심사할 수 있는지 sum 에 저장
        
        
        if(sum >= n) {
            // 처음에는 mid 로 설정
            if(answer == 0){
                answer = mid;
            }
            // 그 다음부터는 answer 와 mid 의 최소값으로 설정
            else {
                answer = min(answer, mid);
            }
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    
    return answer;
}