//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        //1)store2)multiply why to store directly multiply it
        //so
        //prefix=1 for the first ele
        vector<int>ans;
        ans[0]=1;
        for(int i=1;i<arr.size();i++){
            ans[i]=ans[i-1]*arr[i-1];
        }
        int suffix=1;
        int n=arr.size();                      //sc:o(1),tc:o(n)
        for(int i=n-2;i>=0;i--){
            suffix*=arr[i+1];
            ans[i]=ans[i]*suffix;
        }
        return ans;
    }
};

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the product of all
// elements except the current element
vector<int> productExceptSelf(vector<int> &arr) {
    int n = arr.size();
    vector<int> prefProduct(n), suffProduct(n), res(n);

    // Construct the prefProduct array
    prefProduct[0] = 1;
    for (int i = 1; i < n; i++)
        prefProduct[i] = arr[i - 1] * prefProduct[i - 1];

    // Construct the suffProduct array
    suffProduct[n - 1] = 1;
    for (int j = n - 2; j >= 0; j--)
        suffProduct[j] = arr[j + 1] * suffProduct[j + 1];

    // Construct the result array using
    // prefProduct[] and suffProduct[]
    for (int i = 0; i < n; i++)
        res[i] = prefProduct[i] * suffProduct[i];
	
    return res; 
}

int main() {
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productExceptSelf(arr);

    for (int val : res)
        cout << val << " ";
}


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends