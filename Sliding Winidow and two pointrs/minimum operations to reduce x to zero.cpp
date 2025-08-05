#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int t=0;
        for(auto n:nums){
            t+=n;
        }
        if(t==x) return nums.size();
        if(t<x) return -1;
        int target=t-x;
        int i=0,j=0;
        int sum=0,ans=-1;
        int n=nums.size();
        while(j<n){
            sum+=nums[j];
            while(sum>target){
                sum-=nums[i];
                i++;
            }
            if(sum==target){
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans==-1?-1:n-ans;

    }
};