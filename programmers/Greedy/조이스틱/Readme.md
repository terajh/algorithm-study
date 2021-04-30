# 조이스틱

```cpp
#include <string>
#include <vector>
#include <iostream>
#include <numeric>

#define max_count 26
using namespace std;

int solution(string name) {
   int answer = 0;
    vector <int> v;
    for (int i = 0; i < name.size(); i++) {
        v.push_back((name.at(i) - 'A'));
    }
    int cur_pos = 0; // 현재 커서 위치

    while (true) {
        answer += (v[cur_pos] < 26 - v[cur_pos]) ? v[cur_pos] : 26 - v[cur_pos] ;
        v[cur_pos] = 0;
        // 일단 처음에 위또는 아래로 조이스틱 움직인다.
        
        if (accumulate(v.begin(), v.end(), 0) == 0) break;
        // 더이상 처리할 게 있는지 확인 -> 합이 0이면 더이상 할게 없는거
        
        int left = 1, right = 1;
        // 일단 현재 위치에서 왼쪽, 오른쪽으로 한칸씩 간다고 해보자

        int left_cur = (cur_pos - left < 0) ? cur_pos - left + v.size()  : cur_pos - left;
        // 현재 위치에서 왼쪽 한칸갔을 때, 한바퀴도는지? 확인해서 left_cur 처리 
        
        while (v[left_cur] <= 0) { // 왼쪽으로 갔는데도 A 이거나 처리한 문자라면 left 1 추가
            left += 1;
            left_cur = (cur_pos - left < 0) ? cur_pos - left + v.size()  : cur_pos - left;
        }

        int right_cur = (cur_pos + right < v.size()) ? cur_pos + right : (cur_pos + right) % v.size();
        // 현재 위치에서 오른쪽 한칸 갔을 때, 한바퀴 도는지? 확인해서 right_cur 처리
        
        while (v[right_cur] <= 0) { // 오른쪽으로 갔는데도 A 이거나 처리한 문자라면 right 1 추가
            right += 1;
            right_cur = (cur_pos + right < v.size()) ? cur_pos + right : (cur_pos + right) % v.size();
        }
        
        answer += (left < right) ? left : right;
        
        if(left < right) {
            cur_pos = (cur_pos - left < 0) ? cur_pos - left + v.size()  : cur_pos - left;
        }else {
            cur_pos = (cur_pos + right < v.size()) ? cur_pos + right : (cur_pos + right) % v.size();
        }
    }
    return answer;
}
```

![https://s3.us-west-2.amazonaws.com/secure.notion-static.com/959a405f-0a72-49ba-b139-9102b75d467a/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T141959Z&X-Amz-Expires=86400&X-Amz-Signature=d002cc9b0e7c6ad708f9546e767f3be3db25412821d1bbb9002edfc84fbd6eba&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/959a405f-0a72-49ba-b139-9102b75d467a/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T141959Z&X-Amz-Expires=86400&X-Amz-Signature=d002cc9b0e7c6ad708f9546e767f3be3db25412821d1bbb9002edfc84fbd6eba&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

조이스틱을 왼쪽, 오른쪽으로 움직일 지에 대해 greedy 선택, 

조이스틱을 위쪽, 아래쪽으로 움직일 지에 대해 greedy 선택

기본적인 greedy 선택이라 구현문제에 더 가까운 것 같다.