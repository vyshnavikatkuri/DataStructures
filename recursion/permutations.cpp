class Solution {
public:
    void permutations(vector<int>& nums,int idx,int n,vector<vector<int>>&ans){
        if(idx==n) 
        {ans.push_back(nums);
        return;
         }
        for(int i=idx;i<n;i++){
            swap(nums[idx],nums[i]);
            permutations(nums,idx+1,n,ans);
            //backtracking
            swap(nums[idx],nums[i]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        permutations(nums,0,n,ans);
        return ans;
    }
};