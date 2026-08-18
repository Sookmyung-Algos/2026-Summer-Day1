#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int problem=0;

    cin >> n;

    for (int i=0; i<n; i++) {
        int know = 0;
        int m=0;

        for (int j=0; j<3; j++) {
            cin >> m;
            know += m;
        }

        if (know > 1) {
            problem++;
        }
    }

    cout << problem;
}