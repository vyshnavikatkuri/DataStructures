#include<bits/stdc++.h>
// #include<vector
using namespace std;
class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // Complete the function
        int totalones=0;
        for(int i:arr){
            if(i==1) totalones++;
        }
        if(totalones==0) return -1;
        int lensubarray=totalones;
        int i=0,j=0;
        int cnt=0;
        int maxcnt=0;
        while(j<arr.size()){
            if(arr[j]==1) cnt++;
            if(j-i+1==lensubarray){
                maxcnt=max(maxcnt,cnt);
            }
            if(j-i+1>=lensubarray){
                if(arr[i]==1) cnt--;
                i++;
            }
            j++;
        }
        return lensubarray-maxcnt;
    }
};
// A simple solution is to first count total number of 1’s  in the array. Suppose this count is x, 
// now we need to find the subarray of length x with maximum number of 1’s. 
// And minimum swaps required will be the number of 0’s in this subarray of length x.

// Example Dry Run:
// For arr = [1, 0, 1, 0, 1]:

// totalones = 3

// Best window with most 1s: [1, 0, 1] or [1, 0, 1] → has 2 ones

// Swaps = 3 - 2 = 1

// ✅ Time & Space:
// Time: O(n)

// Space: O(1)

// Let me know if you also want the circular version, 
// where you’re allowed to rotate the array and then group the 1s.

// if u want to make all together in a circular array ex:[1,1,0,1,1] total swaps=0
//becos strating  2 ones and ending ones are adjacent
