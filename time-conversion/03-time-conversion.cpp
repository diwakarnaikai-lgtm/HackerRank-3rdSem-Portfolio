#include <iostream>
#include <string>
using namespace std;

string timeConversion(string s) {
    int hour = (s[0] - '0') * 10 + (s[1] - '0');

    if (s[8] == 'A') {
        if (hour == 12) {
            hour = 0;
        }
    } else {
        if (hour != 12) {
            hour += 12;
        }
    }

    s[0] = '0' + hour / 10;
    s[1] = '0' + hour % 10;

    return s.substr(0, 8);
}

int main() {
    string s;
    cin >> s;

    cout << timeConversion(s) << endl;

    return 0;
}