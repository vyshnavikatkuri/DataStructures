class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<int>prevrow;
            vector<vector<int>>ans;
            for(int i=0;i<numRows;i++){
                vector<int>currow(i+1,1);
                for(int j=1;j<i;j++){                     //tc:o(n^2),sc:o(n^2)
                                                        
                    currow[j]=prevrow[j-1]+prevrow[j];
                }
                ans.push_back(currow);
                prevrow=currow;
            }
            return ans;
        }
    };
//     This code generates **Pascal's Triangle** with the given number of rows.

// // ### **Time Complexity**
// // - The outer loop runs **`numRows`** times.
// // - The inner loop, responsible for updating the middle values of the current row, runs **`i-1`** times for each row **`i`** (starting from 2).
// // - The sum of all inner loop operations is:
// //   \[
// //   1 + 2 + 3 + \ldots + (n-1) = \frac{n(n-1)}{2} \approx O(n^2)
// //   \]
// // - **Pushing** each row into the result vector is \( O(n) \) for each row.

// // Thus, the overall **time complexity** is:
// // \[
// // O(n^2)
// // \]

// // ---

// ### **Space Complexity**
// - **`ans`** stores the entire Pascal's Triangle, which contains:
//   \[
//   1 + 2 + 3 + \ldots + n = \frac{n(n+1)}{2} \approx O(n^2)
//   \]
// - **`prevrow`** stores a single row with a maximum size of **`numRows`**, contributing **\( O(n) \)**.
// - **`currow`** is also of size **`i + 1`** for each iteration, contributing **\( O(n) \)**.

// Therefore, the overall **space complexity** is:
// \[
// O(n^2)
// \]