#include<vector>
#include<iostream>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        //1st way u can use normal sorting nlogn
        //using heaps nlog(k)
        //ele target pos is on k pos right side or left side
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        int t=0;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                arr[t]=pq.top();                            //nlog(k)
                pq.pop();
                t++;
            }
        }
        while(!pq.empty()){
            arr[t]=pq.top();
            pq.pop();
            t++;
        }
        
        
        
    }
};