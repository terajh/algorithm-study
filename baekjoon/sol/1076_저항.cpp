#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long LL;
int main() {
    
    map<string, LL> m;
    m["black"] = 0;
    m["brown"] = 1;
    m["red"] = 2;
    m["orange"] = 3;
    m["yellow"] = 4;
    m["green"] = 5;
    m["blue"] = 6;
    m["violet"] = 7;
    m["grey"] = 8;
    m["white"] = 9;

    string a;
    LL res = 0;

    cin >> a;
    res += m[a];
    cin >> a;
    res *=10;
    res += m[a];
    cin >> a;
    res *= pow(10,m[a]);
    cout << res;
    return 0;
}