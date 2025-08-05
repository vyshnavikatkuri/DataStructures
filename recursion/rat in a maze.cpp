//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
string directions="UDLR";
vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
bool isvalid(int row,int col,int n,vector<vector<int>>mat){
    return (row>=0&&col>=0&&row<n&&col<n&&mat[row][col]==1);
}
void possiblepath(int r,int c,vector<vector<int>> &mat,int n,vector<string>&ans,string curpath){
    if(r==n-1&&c==n-1){
        ans.push_back(curpath);
        return;
    }
    mat[r][c]=0;
    for(int i=0;i<4;i++){
        int newr=r+dir[i].first;
        int newc=c+dir[i].second;
        if(isvalid(newr,newc,n,mat)){
            curpath+=directions[i];
            possiblepath(newr,newc,mat,n,ans,curpath);
            curpath.pop_back();
        }
    }
    mat[r][c]=1;
}
class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n=mat.size();
        string curpath="";
        vector<string>ans;
        if(mat[0][0]!=0&&mat[n-1][n-1]!=0){
            possiblepath(0,0,mat,n,ans,curpath);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends


// Time Complexity: O(3^(m*n)), because on every cell we have to try 3 different directions , as we will not check for the cell from which we have visited in the last move.
// Auxiliary Space: O(m*n), Maximum Depth of the recursion tree(auxiliary space).

