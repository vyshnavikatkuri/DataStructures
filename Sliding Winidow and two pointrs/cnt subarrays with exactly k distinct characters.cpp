#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarrays(vector<int>&nums,int k){
        int i=0,j=0;
        int count=0;
        unordered_map<int,int>map;
        while(j<nums.size()){
            map[nums[j]]++;
            while(map.size()>k){
                map[nums[i]]--;
                if(map[nums[i]]==0){
                    map.erase(nums[i]);
                }
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return subarrays(nums,k)-subarrays(nums,k-1);
    }
};