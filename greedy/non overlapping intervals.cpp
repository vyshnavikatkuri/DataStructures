#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    static bool compare(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int lastend=intervals[0][1];
        int cnt=1;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=lastend){
                cnt++;
                lastend=intervals[i][1];
            }
        }
        return intervals.size()-cnt;

    }
};
//min no.of intervals should be removed to make non overlapping intervals
//tc:(nlogn+n) sorting and for loop
// sc:o(1)