//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool ispossible(vector<int>&stalls,int mindist,int k){
        int cows=1;
        int lastpos=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-lastpos>=mindist){
                cows++;
                lastpos=stalls[i];
            }
            if(cows==k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        // Write your code here
        int n=stalls.size();
        int maxele=INT_MIN,minele=INT_MAX;
        for(auto ele:stalls){
            maxele=max(maxele,ele);
            minele=min(minele,ele);
        }
        int left=1,right=maxele-minele,ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(ispossible(stalls,mid,k)){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends