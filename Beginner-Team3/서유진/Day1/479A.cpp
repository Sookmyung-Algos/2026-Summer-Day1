#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[3] = {};

int main() {

    for (int i=0; i<3; i++) {
        cin >> arr[i];
    }

    if (arr[0] > 1 && arr[1] > 1 && arr[2] > 1) {
        cout << arr[0] * arr[1] * arr[2];
    }

    else if (arr[0] == 1 && arr[1] == 1 && arr[2] == 1) {
        cout << 3;
    }

    else {
        int a,b,c;
        a = arr[0];
        b = arr[1];
        c = arr[2];

        int large=0;

        if (a+b*c > large) large = a+b*c;
        if (a*b+c > large) large = a*b+c;
        if (a*b*c > large) large = a*b*c;
        if ((a+b)*c > large) large = (a+b)*c;
        if (a*(b+c) > large) large = a*(b+c);
        if (a+b+c > large) large = a+b+c;

        cout << large;

    }
}