#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int solve(vector<int>& height,int ind,vector<int>&dp){
        if(dp[ind]!=-1) return dp[ind];
        if(ind==0) return 0;
        int twostep=INT_MAX;
        int onestep=solve(height,ind-1,dp)+abs(height[ind-1]-height[ind]);
        if(ind>1){
          twostep=solve(height,ind-2,dp)+abs(height[ind-2]-height[ind]);
        }
        return dp[ind]=min(onestep,twostep);
    }
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int>dp(n,-1);
        int c=solve(height,n-1,dp);
        return c;
        
    }

int minCost(vector<int>& height){
    vector<int>dp(height.size(),0);
    int n=height.size();
    dp[0]=0;
    int right=INT_MAX;
    for(int i=1;i<height.size();i++){
        int left=dp[i-1]+abs(height[i-1],height[i]);
        if(i>1){
            right=dp[i-2]+abs(height[i-2],height[i]);
        }
        dp[i]=min(left,right);
    }
    return dp[n];
}
};