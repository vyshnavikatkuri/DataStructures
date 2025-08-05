class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        vector<int>v(n+1,0);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]++;
            if(v[nums[i]]>1) ans.push_back(nums[i]);
        }
        return ans;
    }
};