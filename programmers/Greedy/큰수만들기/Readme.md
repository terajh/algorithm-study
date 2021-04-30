# 큰수만들기

```cpp
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int numSize = number.size() - k;
    int maxIdx = -1;
    char maxNum;
    
    for(int i=0 ; i<numSize ; i++) {
        maxNum = '0';
        for(int j = maxIdx + 1; j < i + k + 1 ; j++) {
            // i + k + 1 까지의 index 중에서 최대값 찾아야 한다.
            if(maxNum < number.at(j)) {
                maxNum = number.at(j);
                maxIdx = j;
            }
        }
        answer += maxNum;
    }
    return answer;
}
```

![https://s3.us-west-2.amazonaws.com/secure.notion-static.com/c50c4536-77b2-487f-b7d3-5acf78ce61de/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T143626Z&X-Amz-Expires=86400&X-Amz-Signature=62956f6e9ee56f0dc9dfb641fae79d15e57ae44fb15a80488451cf4f7b63076c&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/c50c4536-77b2-487f-b7d3-5acf78ce61de/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210430%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210430T143626Z&X-Amz-Expires=86400&X-Amz-Signature=62956f6e9ee56f0dc9dfb641fae79d15e57ae44fb15a80488451cf4f7b63076c&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

주석을 단 코드가 주된 로직이라 생각한다.

i번째의 수를 고를 때, k 개를 뽑아야 되니까 최소 i부터 k+1 범위에 있는 수중에서 큰 수만을 고르게 되면 결국 전체적으로 봤을 때 최대 값이 생기게 된다.

정확히는 모르겠지만, answer 는 앞자리 수가 크면 클수록 가중치가 크기 때문에 앞에서부터 뽑힐 수 있는 모든 후보군 중에서 큰 값을 뽑는 거 같다.