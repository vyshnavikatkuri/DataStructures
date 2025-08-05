#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int getcount(vector<vector<int>>& matrix,int n,int mid){
        int row=0,col=n-1;
        int cnt=0;
        while(row<n && col>=0){
            if(matrix[row][col]<=mid){
                cnt+=col+1;
                row=row+1;
            }else{
                col=col-1;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0],high=matrix[n-1][n-1];
        while(low<high){
            int mid=low+(high-low)/2;
            int cnt=getcount(matrix,n,mid);
            if(cnt<k){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    }
};
//tc:o(n*log(max-min))
//sc:o(1)
