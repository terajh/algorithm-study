#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


string solution(string number, int k) {
    string answer = "";
    char _max = '0';
    int idx = -1;
    int numsize = number.length() - k;
    
    for(int i = 0 ; i < numsize ; i++){
        _max = '0';
        for(int j = idx + 1 ; j < i + (k + 1) ; j++){
            if(_max < number.at(j)){
                _max = number[j];
                idx = j;
            }
        }
        answer += _max;
    }
    
    return answer;
}