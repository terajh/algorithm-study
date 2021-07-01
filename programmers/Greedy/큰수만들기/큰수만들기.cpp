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