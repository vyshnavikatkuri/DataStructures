// User function template for C++
#include<bits/stdc++.h>
// #include<vector
using namespace std;
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int i=0,j=0,maxlength=0;
        unordered_map<char,int>freq;
        while(j<s.size()){
            freq[s[j]]++;
            if(freq.size()==k){
                maxlength=max(maxlength,j-i+1);
            }
            while(freq.size()>k){
                freq[s[i]]--;
                if(freq[s[i]]==0){
                    freq.erase(s[i]);
                }
                i++;
            }
            
            j++;
        }
        return (maxlength==0)?-1:maxlength;
    }
    
};