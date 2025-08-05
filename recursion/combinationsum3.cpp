class Solution {
public:
    void gcomb(int k,int ind,int n, vector<vector<int>>&ans,vector<int>&ds){
        if(k==0){
            if(n==0){
                ans.push_back(ds);
            }
            return;
        }
        for(int i=ind;i<=9;i++){
            if(i>n) break;
            ds.push_back(i);
            gcomb(k-1,i+1,n-i,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        gcomb(k,1,n,ans,ds);
        return ans;
    }
};