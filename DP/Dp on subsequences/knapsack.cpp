// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,0));
        for(int i=wt[0];i<=capacity;i++){
           dp[0][i]=val[0]*(i/wt[0]);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=capacity;j++){
                int pick=INT_MIN;
                if(wt[i]<=j){
                    pick=val[i]+dp[i][j-wt[i]];
                }
                int notpick=dp[i-1][j];
                dp[i][j]=max(pick,notpick);
            }
        }
        return dp[n-1][capacity];
        
    }
};