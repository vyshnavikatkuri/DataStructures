

class Solution {
    public int longestCommonSubstr(String s1, String s2) {
        // code here
        int m=s1.length(),n=s2.length();
        int[][] dp=new int[m+1][n+1];
        int maxlen=Integer.MIN_VALUE;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1.charAt(i-1)==s2.charAt(j-1)){
                    dp[i][j]=1+dp[i-1][j-1];
                    maxlen=Math.max(maxlen,dp[i][j]);
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return maxlen==Integer.MIN_VALUE?0:maxlen;
    }
} 
