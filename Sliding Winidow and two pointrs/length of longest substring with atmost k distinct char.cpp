#include<bits/stdc++.h>
// #include<vector
using namespace std;
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int i=0,j=0,maxlength=0;
        unordered_map<char,int>freq;
        while(j<s.size()){
            freq[s[j]]++;
            while(freq.size()>k){
                freq[s[i]]--;
                if(freq[s[i]]==0){
                    freq.erase(s[i]);
                }
                i++;
            }
            maxlength=max(maxlength,j-i+1);
            j++;
        }
        return maxlength;
    }
};