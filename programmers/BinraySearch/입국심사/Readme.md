# 입국심사

```cpp
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
```

![https://s3.us-west-2.amazonaws.com/secure.notion-static.com/9670617f-85f0-4303-b902-0285362a8593/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T154408Z&X-Amz-Expires=86400&X-Amz-Signature=3e81f806f02d46f9c60060e34e27100d43e3531d65a55fa38276fbcd5768d909&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/9670617f-85f0-4303-b902-0285362a8593/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T154408Z&X-Amz-Expires=86400&X-Amz-Signature=3e81f806f02d46f9c60060e34e27100d43e3531d65a55fa38276fbcd5768d909&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

기본적인 이분탐색 틀을 사용해서 left, right, mid  를 다루었다.

주 사용한 로직은 전체 시간 자체를 변수로 두어 해당 시간 안에 사람을 입력받은 사람 수 만큼 심사할 수 있느냐를 체크하는 로직이다.

다음 코드가 이번 풀이에 사용한 기본 틀이다.

```cpp
whild(left <= right) {
	mid = (left + right) / 2;
	
	if(mid > answer) right = mid - 1;
	else if(mid < answer) left = mid + 1;
	else break; // mid 가 정답!
}
```