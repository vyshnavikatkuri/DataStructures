#include <iostream>
using namespace std;

void reverseStringWithoutSTL(string &str) {
    int left = 0, right = str.length() - 1;

    // Traverse the string
    while (left < right) {
        // Skip digits on the left
        if (isdigit(str[left])) {
            left++;
        }
        // Skip digits on the right
        else if (isdigit(str[right])) {
            right--;
        }
        // If both characters are non-digits, swap them
        else {
            swap(str[left], str[right]);
            left++;
            right--;
        }
    }
}

int main() {
    string str = "sai2teja";
    cout << "Original string: " << str << endl;
    reverseStringWithoutSTL(str);
    cout << "Reversed string: " << str << endl;
    return 0;
}
