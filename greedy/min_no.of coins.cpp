#include <bits/stdc++.h>
using namespace std;

int findMin(int amount, vector<int> coins)
{
    sort(coins.rbegin(), coins.rend()); // Sort in descending order

    int count = 0;
    for (int coin : coins) {
        if (amount >= coin) {
            int num = amount / coin;
            count += num;
            amount -= num * coin;
        }
    }

    return (amount == 0) ? count : -1;
}

int main()
{
    vector<int> denomination = { 1, 2, 5, 10 };
    int n = 39;
    cout<<findMin(n, denomination);
    return 0;
}
//  When Greedy Fails
// For coins like {1, 3, 4}, amount 6, greedy picks 4 + 1 + 1 = 3 coins, but optimal is 3 + 3 = 2 coins.

// In such cases, use Dynamic Programming instead.
class Solution {
public:
    int count(int ind,vector<int>& coins, int amount,vector<vector<int>>&dp){
        if(amount==0) return 0;;
        if(ind==0) {
            if(amount%coins[0]==0) return amount/coins[0];
            return INT_MAX;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int pick=INT_MAX;
        if(coins[ind]<=amount) {
            int res=count(ind,coins,amount-coins[ind],dp);
            if(res!=INT_MAX) pick=1+res;
        }
        int notpick=count(ind-1,coins,amount,dp);
        return dp[ind][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end());
        int r=count(n-1,coins,amount,dp);
        return r==INT_MAX?-1:r;
    }
};