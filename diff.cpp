#include<bits/stdc++.h>
using namespace std;
bool find(vector<int>arr,int B){
    unordered_set<int>s(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        int ele=arr[i]+B;
        int ele2=arr[i]-B;
        if(s.find(ele)!=s.end()) return true;
        if(s.find(ele2)!=s.end()) return true;
    }
    return false;
}
class Solution {
public:
    // int robbery(int ind,vector<int>& nums,vector<int>&dp){
    //     if(ind<0) return 0;
    //     if(ind==0) return nums[0];
    //     if(dp[ind]!=-1) return dp[ind];
    //     int left=robbery(ind-1,nums,dp);
    //     int right=nums[ind]+robbery(ind-2,nums,dp);
    //     return dp[ind]=max(left,right);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=1;i<n;i++){
           dp[i+1]=max(nums[i]+dp[i-1],dp[i]);
        }
        return dp[n];
        // return robbery(n-1,nums,dp)A;
    }
};