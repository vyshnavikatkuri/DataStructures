#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {   //pse,nse
            int n=heights.size();
            stack<int>st;
            int nse;int maxarea=INT_MIN;
            int pse;
            for(int i=0;i<=n;i++){
                while(!st.empty()&&(i==n||heights[i]<heights[st.top()])){
                    int elei=st.top();
                    st.pop();
                    pse=st.empty()?-1:st.top();
                    nse=i;
                    maxarea=max(maxarea,heights[elei]*(nse-pse-1));
                }
                st.push(i);
            }
            return maxarea;
        }
    };
    //https://youtu.be/Bzat9vgD0fs?si=jDNJ00MSuhhN_ZI1