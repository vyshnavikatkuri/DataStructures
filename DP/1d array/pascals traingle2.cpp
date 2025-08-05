class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int>prevrow;
            for(int i=0;i<=rowIndex;i++){
                vector<int>currow(i+1,1);
                for(int j=1;j<i;j++){
                    currow[j]=prevrow[j-1]+prevrow[j];
                }
                prevrow=currow;
            }
            return prevrow;
        }
    };
    //only give the nth row