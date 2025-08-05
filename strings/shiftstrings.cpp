#include <iostream>
#include <string>
using namespace std;

string shiftString(string s) {
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // Shift lowercase letters
        if (ch >= 'a' && ch <= 'z') {
            s[i] = 'a' + (ch - 'a' + 2) % 26;
        }
        // Shift uppercase letters
        else if (ch >= 'A' && ch <= 'Z') {
            s[i] = 'A' + (ch - 'A' + 2) % 26;
        }
        // Non-alphabetic characters stay unchanged
    }
    return s;
}

int main() {
    string input = "aXbN";
    string result = shiftString(input);
    cout << "Output: " << result << endl;
    return 0;
}
