class Solution {
public:
    // int solve(int n,vector<int>&dp){
    //     if(n<=1) return dp[n]=1;
    //     if(dp[n]!=-1) return dp[n];
    //     int ans=0;
    //     //check for every root
    //     for(int i=1;i<=n;i++){
    //         ans+=solve(i-1,dp)*solve(n-i,dp);
    //     }
    //     return dp[n]=ans;
    // }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        // return solve(n,dp);
        dp[0]=1;
        dp[1]=1;
        int ans;
        //i->no.of nodes
        for(int i=2;i<=n;i++){
            ans=0;
            //j->root node
            for(int j=1;j<=i;j++){
                ans+=dp[j-1]*dp[i-j];
            }
            dp[i]=ans;
        }
        return dp[n];
        //1,2,3 nodes-5 combinations
        //tc:o(n^2) sc:o(n)
    }
};
//this no.of bsts comes equal to catalan number which is (2n+1)!/(n+1)!(n)!