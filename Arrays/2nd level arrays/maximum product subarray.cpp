//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
//see geeks for geeks
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {                   //tc:o(n),sc:o(1)
        // Your Code Here
        int n=arr.size();
        int leftprod=1,rightprod=1,max_prod=INT_MIN;
        for(int i=0;i<n;i++){
            if(leftprod==0) leftprod=1;
            if(rightprod==0) rightprod=1;
            leftprod*=arr[i];
            rightprod*=arr[n-i-1];
            max_prod=max(max(leftprod,rightprod),max_prod);
        }
        return max_prod;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
// def maxProduct(nums):
//     if not nums:
//         return 0

//     maxProd = nums[0]
//     minProd = nums[0]
//     result = nums[0]

//     for i in range(1, len(nums)):
//         if nums[i] < 0:
//             maxProd, minProd = minProd, maxProd
        
//         maxProd = max(nums[i], nums[i] * maxProd)
//         minProd = min(nums[i], nums[i] * minProd)
//         result = max(result, maxProd)

//     return result

// // # Example usage
// // print(maxProduct([2,3,-2,4]))  # Output: 6
// // print(maxProduct([-2,0,-1]))  # Output: 0
