//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {                                         //tc:0(n),sc:o(1)
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n=arr.size();
        int stop=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                stop=i;
                break;
            }
        }
        if(stop==-1) {
            reverse(arr.begin(),arr.end());
            return;
        }
        for(int i=n-1;i>stop;i--){
            if(arr[i]>arr[stop]){
                swap(arr[i],arr[stop]);
                break;
            }
        }
        reverse(arr.begin()+stop+1,arr.end());
        
    }
};


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
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends