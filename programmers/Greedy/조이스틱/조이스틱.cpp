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
    int cur_pos = 0;

    while (true) {
        answer += (v[cur_pos] < 26 - v[cur_pos]) ? v[cur_pos] : 26 - v[cur_pos] ;
        v[cur_pos] = 0;
        if (accumulate(v.begin(), v.end(), 0) == 0) break;
        int left = 1, right = 1;

        int left_count = (cur_pos - left < 0) ? cur_pos - left + v.size()  : cur_pos - left;
        while (v[left_count] <= 0) {
            left += 1;
            left_count = (cur_pos - left < 0) ? cur_pos - left + v.size()  : cur_pos - left;
        }

        int right_count = (cur_pos + right < v.size()) ? cur_pos + right : (cur_pos + right) % 5;
        while (v[right_count] <= 0) {
            right += 1;
            right_count = (cur_pos + right < v.size()) ? cur_pos + right : (cur_pos + right) % 5;
        }
        answer += (left < right) ? left : right;
        cur_pos += (left < right) ? -left : right;
        if (cur_pos < 0) {
            cur_pos = cur_pos + v.size() ;
        }
        else if (cur_pos > v.size()) {
            cur_pos %= 5;
        }

    }
    return answer;
}