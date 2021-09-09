#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <set>
using namespace std;


int main() {
    set<int> a;
    int in;
    for (int i = 0; i < 10; i++) {
        cin >> in;
        a.insert(in%42);
    }
    cout << a.size();
    return 0;
}