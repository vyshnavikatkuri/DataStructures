//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr, int ind,int target,vector<vector<int>>&dp){
        if(dp[ind][target]!=-1) return dp[ind][target];
        if(ind==0){
            if(target==0 && arr[ind]==0) return 2;
            if(target==0 || arr[ind]==target) return 1;
            return 0;
        } 
        int left=0;
        if(arr[ind]<=target){
            left= solve(arr,ind-1,target-arr[ind],dp);
        }
        int right=solve(arr,ind-1,target,dp);
        return dp[ind][target]=left+right;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(arr,n-1,target,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        const int mod = 1e9 + 7;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Handle 0 explicitly: two options for 0 - pick or not pick
        if (arr[0] == 0) {
            dp[0][0] = 2; // pick or not pick
        } else {
            dp[0][0] = 1; // not pick
            if (arr[0] <= target) {
                dp[0][arr[0]] = 1; // pick
            }
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= target; t++) {
                int notPick = dp[i - 1][t];
                int pick = 0;
                if (arr[i] <= t) {
                    pick = dp[i - 1][t - arr[i]];
                }
                dp[i][t] = (pick + notPick) % mod;
            }
        }

        return dp[n - 1][target];
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}
