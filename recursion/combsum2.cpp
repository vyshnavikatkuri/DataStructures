class Solution {
public:
    void gCombinations(vector<int>& candidates, int target,int ind,vector<vector<int>>&ans,vector<int>&ds){
          if(target==0) {
                ans.push_back(ds);return;  
          } 
          for(int i=ind;i<candidates.size();i++){
            if(i>ind &&candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            gCombinations(candidates,target-candidates[i],i+1,ans,ds);
            ds.pop_back();
          }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        gCombinations(candidates,target,0,ans,ds);
        return ans;
    }
};