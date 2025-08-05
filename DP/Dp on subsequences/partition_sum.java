package DP.Dp on subsequences;

public class partition_sum {
    
}
class Solution {
    public boolean recursion(int ind,int tar,int[] nums,Boolean[][] dp){
        if(tar==0) return true;
        if(ind==0) return nums[0]==tar;
        if(dp[ind][tar]!=null) return dp[ind][tar];
        boolean pick=false;
        if(nums[ind]<=tar) pick=recursion(ind-1,tar-nums[ind],nums,dp);
        boolean notpick=recursion(ind-1,tar,nums,dp);
        return dp[ind][tar]=pick||notpick;

    }
    public boolean canPartition(int[] nums) {
        int sum=0;
        for(int ele:nums){
            sum+=ele;
        }
        if(sum%2!=0) return false;
        int n=nums.length;
        Boolean[][] dp=new Boolean[n][sum/2+1];
        return recursion(n-1,sum/2,nums,dp);
    }
}
