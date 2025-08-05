#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>>job;
        for(int i=0;i<profit.size();i++){
            // job[i].first=profit;
            // job[i].second=deadline;
            job.push_back({profit[i],deadline[i]});
        }
        sort(job.rbegin(),job.rend());
        int maxDeadline=0;
        for(int i=0;i<job.size();i++){
            maxDeadline=max(maxDeadline,job[i].second);
        }
        vector<int>slot(maxDeadline+1,-1);
        int maxprofit=0,cnt=0;
        for(int i=0;i<job.size();i++){
            int jobprofit=job[i].first;
            int jobdeadline=job[i].second;
            for(int j=jobdeadline;j>=1;j--){
                if(slot[j]==-1){
                    slot[j]=1;
                    maxprofit+=jobprofit;
                    cnt++;
                    break;
                }
            }
        }
        return {cnt,maxprofit};
        
    }
};