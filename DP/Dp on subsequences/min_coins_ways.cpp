#include <bits/stdc++.h>
using namespace std;
Class Solution {
public:
    int ways(int ind,vector<int>& coins,int amount,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(ind==0){
            if(amount%coins[0]==0) return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int pick=0;
        if(coins[ind]<=amount){
            pick=ways(ind,coins,amount-coins[ind],dp);
        }
        int nonpick=ways(ind-1,coins,amount,dp);
        return dp[ind][amount]=pick+nonpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(int)
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=amount;j++){
        //         if(coins[i-1]<=j){
        //             dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
        //         }
        //         else{
        //             dp[i][j]=dp[i-1][j];
        //         }
        //     }
        // }
        // return dp[n][amount];
        return ways(n-1,coins,amount,dp);
    }
};