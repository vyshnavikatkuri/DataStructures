//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int priorities(char c){
        if (c=='^')
            return 3;
        if(c=='*'||c=='/') return 2;
        if(c=='+'||c=='-') return 1;
        return 0;
    }
    string infixToPostfix(string& s) {
        string news;
        stack<char>st;
        for(auto c:s){
            if(isalpha(c)||isdigit(c)){
                news+=c;
                continue;
            } 
            if(c=='(') st.push(c);
            else if(c==')'){
                while(!st.empty()&&st.top()!='('){
                    news+=st.top();
                    st.pop();
                }
                 if(!st.empty()) st.pop();
            }else{
                while(!st.empty()&&priorities(st.top())>=priorities(c)){
                    news+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            news+=st.top();
            st.pop();
        }
        return news;
        
    }
};



//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends