#include <string>
#include <iostream>

using namespace std;
int main() {
    string tp;
    cin >> tp;
    for(int i=0 ; i<tp.size() ; i++) {
        cout << tp[i];
        if((i+1)%10 == 0) cout << "\n";
    }
    return 0;
}