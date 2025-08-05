#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxreach) return false;
            maxreach=max(maxreach,i+nums[i]);

        }
        return maxreach>=nums.size()-1;
    }
};
// ✅ Greedy Idea in Jump Game:
// At each index, you greedily try to go as far as possible, always keeping track of the maximum reachable index.