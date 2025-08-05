#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        //check arrival and departure times increase cnt for arrival and decrease for 
        // departure
        int cnt=0;
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int maxplatforms=0;
        int i=0,j=0;
        while(i<arr.size() && j<dep.size()){
            if(arr[i]<=dep[j]){
                cnt++;
                i++;
            }else{
                cnt--;
                j++;
            }
            maxplatforms=max(maxplatforms,cnt);
        }
        return maxplatforms;
    }
};
//tc:o(nlogn+nlogn+n)=o(nlogn),sc:o(1)
