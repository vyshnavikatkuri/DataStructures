#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i,vector<vector<int>>& isConnected,vector<int>&vis){
        vis[i]=1;
        for(int j=0;j<isConnected[i].size();j++){
            if(vis[j]!=1 && isConnected[i][j]==1){
                dfs(j,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>vis(isConnected.size(),0);
        int c=0;
        for(int i=0;i<isConnected.size();i++){
              if(!vis[i]){
                  c+=1;
                  dfs(i,isConnected,vis);
              }
        }
        return c;
    }
};