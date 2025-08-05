//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int maxProduct(vector<int> arr) {
        // code here
        int n=arr.size();
        int first = INT_MIN, 
        second = INT_MIN, third = INT_MIN;
        int minA = INT_MAX, minB = INT_MAX;
        for(int i=0;i<n;i++){
            int ele=arr[i];
            if(ele>=first){
                third=second;
                second=first;
                first=ele;
            }else if(ele>=second && ele<first){
                third=second;
                second=ele;
            }else if(ele>=third && ele<second){
                third=ele;
            }
            if(ele<=minA){
                minB=minA;
                minA=ele;
            }else if(ele<=minB && ele>minA){
                minB=ele;
            }
        }
        return max(minA*minB*first,first*second*third);
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends