class Solution {
public:
    void backtrack(int ind,string comb,string digits,vector<string>&res,unordered_map<char,string>mp){
        if(ind==digits.size()){
            res.push_back(comb);
            return;
        }
        string letters=mp.at(digits[ind]);
        for(char letter:letters){
            backtrack(ind+1,comb+letter,digits,res,mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.empty()) return res;
        unordered_map<char,string>mp={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        backtrack(0,"",digits,res,mp);
        return res;
    }
};
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
// | Metric            | Complexity | Explanation               |
// | ----------------- | ---------- | ------------------------- |
// | Time              | O(kⁿ)      | Generate all combinations |
// | Space (Recursion) | O(n)       | Depth of call stack       |
// | Space (Result)    | O(n × kⁿ)  | Storing all combinations  |
// Time complexity: O(kⁿ)
// Where k is max 4 (for '7' and '9').

// Why?
// At each level (index ind), the for loop runs k times.

// The recursion goes n levels deep.

// So total combinations = k × k × ... (n times) = kⁿ
// Space Complexity
// There are two main components:

// 1. Recursive call stack
// Maximum depth = n (length of the input)

// So stack space = O(n)

// 2. Result storage
// There are kⁿ combinations

// Each string in result is of length n

// So space for results = O(n × kⁿ)

// In practice, if you're not counting the result storage (output space), then just the recursion space is O(n)
