#include<bits/stdc++.h>
// #include<vector
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>freq;
        int left=0, cnt=0,n=s.size();
        for(int right=0;right<s.size();right++){
            freq[s[right]]++;
            while(freq['a']>0 && freq['b']>0 && freq['c']>0){
                cnt+=(n-right);
                freq[s[left]]--;
                left++;
            }
        }
        return cnt;
    }
};
//tc:o(n)//sc:o(m)
//O(n) — Every character is visited at most twice (once by right, once by left).

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
// Example 2:

