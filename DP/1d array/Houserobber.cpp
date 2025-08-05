#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int robbery(int ind,vector<int>& nums,vector<int>&dp){
        if(ind<0) return 0;
        if(ind==0) return nums[0];
        if(dp[ind]!=-1) return dp[ind];
        int left=robbery(ind-1,nums,dp);
        int right=nums[ind]+robbery(ind-2,nums,dp);
        return dp[ind]=max(left,right);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return robbery(n-1,nums,dp);
    }
};