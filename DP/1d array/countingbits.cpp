class Solution {
    public:
        vector<int> countBits(int n) {
            int sub=1;
            vector<int>dp(n+1);
            dp[0]=0;
            for(int i=1;i<=n;i++){
                if(sub*2==i){
                    sub=i;
                }
                dp[i]=dp[i-sub]+1;
            }
            return dp;
        }
    };
    //Example 1:

// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// Example 2:

// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101
 