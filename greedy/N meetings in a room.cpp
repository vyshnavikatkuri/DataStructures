#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    struct Meeting{
        int st;
        int end;
    };
    static bool compare(Meeting a,Meeting b){
        return a.end<b.end;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<Meeting> meetings(n);
        for(int i=0;i<start.size();i++){
            meetings[i].st=start[i];
            meetings[i].end=end[i];
        }
        sort(meetings.begin(),meetings.end(),compare);
        int cnt=1;
        int lastend=meetings[0].end;
        for(int i=1;i<start.size();i++){
            if(meetings[i].st>=lastend){
                cnt++;
                lastend=meetings[i].end;
            }
        }
        return cnt;
        
    }
};