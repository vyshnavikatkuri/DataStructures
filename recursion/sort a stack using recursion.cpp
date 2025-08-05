#include<bits/stdc++.h>
using namespace std;
class SortedStack{
public:
    stack<int> s;
    void sort();
};


/* The below method sorts the stack s
you are required to complete the below method */
void sortIndex(stack<int>&st,int x){
    if(st.empty()||x>st.top()){
        st.push(x);
        return;
    }
    int temp=st.top();
    st.pop();
    sortIndex(st,x);
    st.push(temp);
}
void SortedStack ::sort() {
    // Your code here
    if(!s.empty()){
        int x=s.top();
        s.pop();
        sort();
        sortIndex(s,x);
    }
}