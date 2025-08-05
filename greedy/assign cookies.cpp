#include<bits/stdc++.h>
// #include<vector
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                i++;
            }
            j++;
        }
        return i;
    }
};
// Time: O(n log n + m log m) → due to sorting

// Space: O(1) → no extra space
// Choose the smallest cookie that can satisfy the current child.

// We never “save” a bigger cookie for a smaller greed, we use it immediately if it satisfies someone.

// This greedy choice ensures:

// We don’t waste large cookies on children with small greed.

// We maximize the number of children who get cookies.

