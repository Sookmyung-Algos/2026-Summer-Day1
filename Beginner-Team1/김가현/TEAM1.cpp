// 231A TEAM1

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    int P, V, T;
    int implement=0;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> P >> V >> T;
        if ((P+V+T) >= 2) implement += 1;
    }
    
    cout << implement;
}