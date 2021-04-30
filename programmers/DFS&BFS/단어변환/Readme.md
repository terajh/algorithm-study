# 단어변환

```cpp
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
int _min = 51;
int _count = 0;

bool oneChange(string a, string b) {
    int changeCount = 0;
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a.at(i) != b.at(i)) changeCount += 1;
    }
    return changeCount == 1;
}
vector<int> dfs(string currentString, vector<string> words, vector<int> check, string target) {
    if (currentString == target) {
        _min = min(_min, _count);
        return check;
    }
    for (int i = 0; i < words.size(); i++) {
        if (check[i] == 0 && oneChange(currentString, words[i])) {
            check[i] = 1; _count += 1;
            check = dfs(words[i], words, check, target);
            check[i] = 0; _count -= 1;
        }
    }
    return check;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<int> check(words.size(), 0);
    check = dfs(begin, words, check, target);

    return _min == 51 ? 0 : _min;
}
```

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/70f127a0-c588-440d-9a41-1088214a6803/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/70f127a0-c588-440d-9a41-1088214a6803/Untitled.png)

oneChange 함수에서 string 두 개에 대해 하나의 문자만 바꿧는지 체크하는 것만 짯으면

기본적인 dfs 알고리즘으로 풀 수 있다.