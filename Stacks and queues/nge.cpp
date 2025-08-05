
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nge(vector<int>arr,stack<int>&st){
    vector<int>ans(arr.size(),-1);
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        int ele=arr[i];
        while(!st.empty() && st.top()<=ele){
            st.pop();
        }
        if(!st.empty()) ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}
int main(){
    stack<int>st;
    vector<int>arr={1,2,8,3,6,8,3};
    vector<int>ans=nge(arr,st);
    for(int i:ans){
        cout<<i<<" ";
    }

}

