
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//using two stacks//finding min ele at each step
class MinStack {
    stack<pair<int,int>>st;
    int minval;
public:
    MinStack() {
        minval=INT_MAX;
    }
    void push(int val) {
        if(val<minval){
            minval=val;
        }
        st.push({val,minval});
    }
    void pop() {
        if(st.empty()) cout<<"st is empty";
        st.pop();
    }
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//using single stack and having in pairs
class MinStack {
    stack<pair<int,int>>st;
    
public:
    MinStack() {

    }
    void push(int val) {
        int mini;
        if(st.empty()){
            mini=val;
        }else{
            mini=min(st.top().second,val);
        }
        st.push({val,mini});
    }
    void pop() {
        if(st.empty()) return;
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */