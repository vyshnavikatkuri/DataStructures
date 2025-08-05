#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>rightsmaller(n,-1);
        vector<int>leftsmaller(n,-1);
        stack<int>st;
        
        //right side smaller ele or nearest right smaller
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            rightsmaller[i]=st.empty()?n:st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        //left side smaller ele or nearsest left boundary
        for(int i=0;i<n;i++){
             while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) leftsmaller[i]=st.top();
            st.push(i);
        }
        //cal area
        int curarea=0,maxarea=0;
        for(int i=0;i<n;i++){
            curarea=heights[i]*(rightsmaller[i]-leftsmaller[i]-1);
            maxarea=max(maxarea,curarea);
        }
        return maxarea;
    }
};