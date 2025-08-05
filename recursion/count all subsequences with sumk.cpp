#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        int cnt=0;
        countS(nums,0,k,cnt);
        return cnt;
    
    }
    void countS(vector<int>& nums, int ind,int target,int &cnt){
          if(ind==nums.size()){
              if(target==0) {
                cnt++;
               
          }
                return;
          }
          
          if(nums[ind]<=target){
            countS(nums,ind+1,target-nums[ind],cnt);  //pick
          }
          countS(nums,ind+1,target,cnt);  //not pick

    }
    
};
