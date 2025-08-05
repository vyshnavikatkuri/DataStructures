#include<string>
using namespace std;
class Solution {
public:
    string expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";

        string longest = "";
        
        for (int i = 0; i < s.length(); i++) {
            // Odd-length palindrome (center is a single character)
            string palindrome1 = expandAroundCenter(s, i, i);
            // Even-length palindrome (center is between two characters)
            string palindrome2 = expandAroundCenter(s, i, i + 1);

            // Update the longest palindrome
            if (palindrome1.length() > longest.length()) {
                longest = palindrome1;
            }
            if (palindrome2.length() > longest.length()) {
                longest = palindrome2;
            }
        }

        return longest;
    }
};
// b a b a b a d
//check for every letter
// b palindrome,b a not palindrome
// a ok,b a b ok,limit goes not palindrome, a b not palindrome
// b ok,a b a ok,b a b a b ok highest,limit reaches, b a not palindrome check all
//even and odd length palindromes
//time complexity=o(n^2),sc:o(n);
