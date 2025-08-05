class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>freq(n*n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freq[grid[i][j]]++;
            }
        }
        vector<int>arr;
        int secondele,firstele;
        for(int i=1;i<freq.size();i++){
            if(freq[i]==0) secondele=i;
            if(freq[i]==2) firstele=i;
        }
        arr.push_back(firstele);
        arr.push_back(secondele);
        return arr;

    }
};
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int expecsum=(n*n*(n*n+1))/2;
        unordered_set<int>s;
        int actsum=0;
        vector<int>arr;
        int firstele;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               actsum+=grid[i][j];
               if(s.find(grid[i][j])!=s.end()){
                  firstele=grid[i][j];
                  arr.push_back(firstele);
               }
               s.insert(grid[i][j]);
            }
        }
        int secondele=expecsum+firstele-actsum;
        arr.push_back(secondele);
        return arr;
    }
};