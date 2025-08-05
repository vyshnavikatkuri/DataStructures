#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int recursion(int ind, int size, vector<int> &price, vector<vector<int>>& dp) {
        if (ind == 0) {
            return (size * price[0]);
        }
        if (dp[ind][size] != -1) return dp[ind][size];

        int pick = INT_MIN;
        if (ind + 1 <= size) {
            pick = price[ind] + recursion(ind, size - (ind + 1), price, dp);
        }
        int notpick = recursion(ind - 1, size, price, dp);

        return dp[ind][size] = max(pick, notpick);
    }

    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return recursion(n - 1, n, price, dp);
    }
};

int main() {
    Solution sol;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20}; // prices for rod lengths 1 to 8
    int result = sol.cutRod(price);
    cout << "Maximum Obtainable Value: " << result << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Base case: fill first row (only using rod length 1)
        for (int size = 0; size <= n; size++) {
            dp[0][size] = size * price[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int size = 0; size <= n; size++) {
                int notpick = dp[ind - 1][size];
                int pick = INT_MIN;
                int rod_length = ind + 1;

                if (rod_length <= size) {
                    pick = price[ind] + dp[ind][size - rod_length];
                }

                dp[ind][size] = max(pick, notpick);
            }
        }

        return dp[n - 1][n];
    }
};

int main() {
    Solution sol;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20}; // prices for rod lengths 1 to 8
    int result = sol.cutRod(price);
    cout << "Maximum Obtainable Value: " << result << endl;
    return 0;
}
