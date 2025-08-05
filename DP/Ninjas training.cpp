//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int day,int last,vector<vector<int>>&arr,vector<vector<int>>&dp){
        if(dp[day][last]!=-1) return dp[day][last];
        if(day==0){
            int maxi=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    maxi=max(maxi,arr[day][task]);
            }
        }
        return maxi;
        }
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                int points=arr[day][task]+f(day-1,task,arr,dp);
                maxi=max(maxi,points);
            }
        }
        return dp[day][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return f(n-1,3,arr,dp);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends

//TC:o(n*4) SC:o(N)+o(N*4)

//Tablulation Approach
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        dp[0][1]=max(arr[0][0],arr[0][2]);
        dp[0][2]=max(arr[0][0],arr[0][1]);
        dp[0][0]=max(arr[0][1],arr[0][2]);
        dp[0][3]=max(dp[0][1],max(dp[0][2],dp[0][0]));
        for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                dp[day][last]=0;
                for(int task=0;task<3;task++){
                    if(task!=last){
                       int points=arr[day][task]+dp[day-1][task];
                       dp[day][last]=max(dp[day][last],points);
                    }
            }
        }
        }
        return dp[n-1][3];
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends