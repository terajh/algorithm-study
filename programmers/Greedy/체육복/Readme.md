# 체육복

```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isOk(int a, int b) {
    return (a +1 == b || a == b+1);
}
int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    vector<int> check(reserve.size(), 0);
    
    int answer = n - lost.size();
    for(int i=0 ; i<lost.size() ; i++) {
        for(int j=0 ; j<reserve.size() ;j++) {
            if(lost[i] == reserve[j]){
                lost[i] = -1;
                reserve[j] = -1;
                answer += 1;
            }
        }
    }
   
    for(int i=0 ; i<reserve.size() ; i++) {
        if(reserve[i] != -1) {
            for(int j=0 ; j<lost.size() ;j++) {
                if(isOk(lost[j], reserve[i]) && check[j] != 1) {
                    check[j] = 1;
                    answer += 1;
                    break;
                }
            }
        }
    }
    
    return answer;
}
```

![https://s3.us-west-2.amazonaws.com/secure.notion-static.com/5f3e3634-ef86-45c2-986a-151b3c8ce43f/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T131053Z&X-Amz-Expires=86400&X-Amz-Signature=975d29dbd448a601d8e384c7a35b402ba179d7d3da7aa5f6a76226a038ed4fce&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/5f3e3634-ef86-45c2-986a-151b3c8ce43f/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T131053Z&X-Amz-Expires=86400&X-Amz-Signature=975d29dbd448a601d8e384c7a35b402ba179d7d3da7aa5f6a76226a038ed4fce&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

매우 기본적인 문제이다. 

이 때 lost 배열과 reserve 배열 for 순서를 바꿔도 답은 똑같다.