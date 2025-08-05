// User function Template for C++

//Back-end complete function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int wt=0;
        int t=0;
        for(int i=0;i<bt.size();i++){        //waiting time for 1st is 0 time t=0
                                              //wt for 2nd is 1 becoz time t=1
            
            wt+=t;
            t+=bt[i];
        }
        return wt/bt.size();
    }
};