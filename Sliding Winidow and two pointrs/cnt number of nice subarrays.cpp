#include<bits/stdc++.h>
// #include<vector
using namespace std;
class Solution {
public:
    int cntsubarrays(vector<int>&nums,int k){
        int i=0,j=0;
        int sum=0,cnt=0;
        while(j<nums.size()){
            sum+=(nums[j]%2);
            while(sum>k){
                sum-=(nums[i]%2);
                i++;
            }         
            cnt+=j-i+1;  //no.of subarrays sum less than equal to goal
            j++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return cntsubarrays(nums,k)-cntsubarrays(nums,k-1);
    }
};