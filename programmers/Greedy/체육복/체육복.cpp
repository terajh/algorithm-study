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