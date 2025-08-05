class Solution {
    public:
        bool isvalid(vector<vector<int>>& grid,int row,int col,int expval){
             if(row>=grid.size()||col>=grid.size()||row<0||col<0||grid[row][col]!=expval){
                return false;
             }
             if(expval==grid.size()*grid.size()-1) return true;
             bool ans1=isvalid(grid,row-2,col+1,expval+1);
             bool ans2=isvalid(grid,row-1,col+2,expval+1);
             bool ans3=isvalid(grid,row+1,col+2,expval+1);
             bool ans4=isvalid(grid,row+2,col+1,expval+1);
             bool ans5=isvalid(grid,row+2,col-1,expval+1);
             bool ans6=isvalid(grid,row+1,col-2,expval+1);
             bool ans7=isvalid(grid,row-1,col-2,expval+1);
             bool ans8=isvalid(grid,row-2,col-1,expval+1);
             if(ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8){
                return true;
             } 
             return false;
        }
        bool checkValidGrid(vector<vector<int>>& grid) {
            int expval=0;
            return isvalid(grid,0,0,expval);
        }
    };