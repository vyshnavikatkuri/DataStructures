class Solution {
public:
    int ways(int ind,int n,vector<int>&dp){
        if(ind==n) return 1;
        if(ind>n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=ways(ind+1,n,dp)+ways(ind+2,n,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return ways(0,n,dp);
    }
};
class Solution {
public:
    // int ways(int ind,int n,vector<int>&dp){
    //     if(ind==n) return 1;
    //     if(ind>n) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     return dp[ind]=ways(ind+1,n,dp)+ways(ind+2,n,dp);
    // }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        // return ways(0,n,dp);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};