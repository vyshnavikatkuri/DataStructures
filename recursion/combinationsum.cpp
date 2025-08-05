class Solution {
public:
    void gCombinations(vector<int>& candidates, int target,int ind,vector<vector<int>>&ans,
        vector<int>&ds){     
            if(ind==candidates.size()){
                  if(target==0){
                    ans.push_back(ds);
                  }
                  return;
            }
            if(candidates[ind]<=target){
                ds.push_back(candidates[ind]);
                gCombinations(candidates,target-candidates[ind],ind,ans,ds);
                ds.pop_back();
            }
            gCombinations(candidates,target,ind+1,ans,ds);

        }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        gCombinations(candidates,target,0,ans,ds);
        return ans;
    }
};