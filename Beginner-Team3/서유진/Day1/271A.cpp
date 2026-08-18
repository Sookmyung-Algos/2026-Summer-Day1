#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[4] = {};

int beauty() {
    if (arr[0] == arr[1]) {
        arr[1]++;

        if (arr[1] > 9) {
            arr[0]++;
            arr[1] = 0;
        }

        arr[2] = arr[1] + 1;
        arr[3] = arr[2] + 1;

        return beauty();
    }

    if (arr[0] == arr[2] || arr[1] == arr[2]) {
        arr[2]++;

        if (arr[2] > 9) {
            arr[0]++;
            arr[1] = 0;
            arr[2] = 1;
            arr[3] = 2;

            return beauty();
        }

        return beauty();
    }

    if (arr[0] == arr[3] || arr[1] == arr[3] || arr[2] == arr[3]) {
        arr[3]++;

        if (arr[3] > 9) {
            arr[1]++;

            if (arr[1] > 9) {
                arr[0]++;
                arr[1] = 0;
                arr[2] = 1;
                arr[3] = 2;
            }
            else {
                arr[2] = arr[1] + 1;
                arr[3] = arr[2] + 1;

                if (arr[3] > 9) {
                    arr[0]++;
                    arr[1] = 0;
                    arr[2] = 1;
                    arr[3] = 2;
                }
            }

            return beauty();
        }

        return beauty();
    }

    return 0;
}

int main() {
    int year;
    cin >> year;
    year++;

    arr[0] = year / 1000;
    arr[1] = (year - 1000 * arr[0]) / 100;
    arr[2] = (year - 1000 * arr[0] - 100 * arr[1]) / 10;
    arr[3] = year - 1000 * arr[0] - 100 * arr[1] - 10 * arr[2];

    beauty();

    for (int i = 0; i < 4; i++) {
        cout << arr[i];
    }
}