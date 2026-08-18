#include <iostream>
#include <string>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

string year;
cin >> year;
while (1){
    int y = stoi(year)+1;
    year = to_string(y);
    if (year[0] != year[1] && year[0] != year[2]
    && year[0] != year[3] && year[1] != year[2]
    && year[1] != year[3] && year[2] != year[3])
    {
        cout << y;
        return 0;
    }
}
return 0;
}