//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int>&arr,int low,int mid,int high){
        int left=low,right=mid+1;
        vector<int>temp;
        int invcnt=0;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                invcnt+=mid-left+1;
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=0;i<temp.size();i++){
            arr[i+low]=temp[i];
        }
        return invcnt;
    }
    int mergesort(vector<int>&arr,int low,int high){
        if(low<high){
            int mid=low+(high-low)/2;
            int leftcnt=mergesort(arr,low,mid);
            int rightcnt=mergesort(arr,mid+1,high);
            int inv=merge(arr,low,mid,high);
            return leftcnt+rightcnt+inv;
        }
        return 0;
        
    }
    int inversionCount(vector<int> &arr) {
       int low=0;
       int high=arr.size()-1;
       int cnt=mergesort(arr,low,high);
       return cnt;
        
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends