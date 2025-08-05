#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#include<vector>
vector<int> recursion(int ind,vector<int>&ans,vector<int>arr,int sum){
      if(ind==arr.size()){
        ans.push_back(sum);
        return;
      }
      recursion(ind+1,ans,arr,sum+arr[ind]);       //tc:2^n+2^n(logn) 2 2 2 every ele has 2 chances,2^N log(2^n) is for sorting 2^n ele
      recursion(ind+1,ans,arr,sum);
}
int main(){
    vector<int>arr={4,6,3};
    vector<int>ans;
    ans=recursion(0,ans,arr,0);
    sort(ans.begin(),ans.end());
    
}
