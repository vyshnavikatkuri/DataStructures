#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
class MyStack {
    queue<int>q1,q2;
   
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }                                  //using single queue:
                                            //first push ele into the queue,then remove size-1 ele
                                            //from front,and push all ele into the queue                                 
        swap(q1,q2);
    }
    
    int pop() {
       if(q1.empty()) return -1;
       int temp= q1.front();
       q1.pop();
       return temp;
    }
    
    int top() {
       return q1.empty()?-1:q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
