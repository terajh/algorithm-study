#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int check[100];
int a = 100;
bool oneChange(string a, string b) {
    int _count = 0;
    for(int i=0 ; i<a.size(); i++) {
        if(a.at(i) != b.at(i)) _count += 1;
    }
    if(_count == 1) return true;
    else return false;
}
void dfs(int n, string b, string t, vector<string> w) {
    if(b.compare(t) == 0) {
        a = min(a, n);
        return;
    }
    for(int i=0 ; i<w.size() ; i++) {
        if(!oneChange(b, w[i])) continue;
        if(check[i]==0) {
            check[i] = 1;
            dfs(n+1, w[i], t, w);
            check[i] = 0;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    else {
        dfs(0, begin, target, words);
        return a;
    }
}