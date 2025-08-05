#include <bits/stdc++.h>
using namespace std;

// Function to check if there is a subset of 'arr' with a sum equal to 'target'
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // If the target sum is 0, we have found a subset
    if (target == 0)
        return true;

    // If we have reached the first element in 'arr'
    if (ind == 0)
        return arr[0] == target;

    // If the result for this subproblem has already been computed, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Try not taking the current element into the subset
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    // Try taking the current element into the subset if it doesn't exceed the target
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the dp array to avoid recomputation
    return dp[ind][target] = notTaken || taken;
}

// Function to check if there is a subset of 'arr' with a sum equal to 'k'
bool subsetSumToK(int n, int k, vector<int>& arr) {
    // Initialize a 2D DP array for memoization
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    // Call the recursive subsetSumUtil function
    return subsetSumUtil(n - 1, k, arr, dp);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    // Call the subsetSumToK function and print the result
    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}
// ime Complexity: O(n × sum)
// 🔍 Why?
// dp[ind][target] is computed only once for each unique (ind, target) pair.

// There are n indices and up to sum values for the target.

// So total unique subproblems = n * sum.
// Space Complexity: O(n × sum) + O(n)
// 1. DP Table: vector<vector<int>> dp(n, vector<int>(sum+1, -1));
// It stores results for all (ind, target) combinations.

// Size = n × (sum+1) → O(n × sum)

// 2. Recursion Stack Space:
// Maximum depth of recursion = n (as ind decreases from n-1 to 0).

// So additional stack space = O(n).

// ➕ Total Space:
// O(n × sum) (DP table) + O(n) (call stack)

// = O(n × sum) overall (since it's the dominant term)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<arr.size();i++) dp[i][0]=true;
        if(arr[0]<=sum){
            dp[0][arr[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool pick=false;
                if(arr[i]<=j) pick=dp[i-1][j-arr[i]];
                bool notpick=dp[i-1][j];
                dp[i][j]=pick||notpick;
            }
        }
        return dp[n-1][sum];
    }
};