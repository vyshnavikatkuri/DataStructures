#include<Stdio.h>
#include<iostream>
using namespace std;
#define MAX 100
class Stack{
    public:
    int top=-1;
    int arr[MAX];
    void push(int x){
        if(top==MAX-1){
            cout<<  "stack overflow";
            return;
        }
        arr[++top]=x;
    }
    int pop(){
        if(top==-1){
            cout<<"stack is empty or stack underflow";
            return -1;
        }
        int y=arr[top];
        top--;
    }
    int topele(){
        if(top<0) {
            cout<<"stack is empty";return -1;}
        return arr[top];
    }
    bool isempty(){
        if(top<0) return true;
        else return false;
    }
};
int main(){
        Stack s;
        s.push(2);
        s.push(3);
        s.push(10);
        int yx=s.pop();
        cout<<yx;
        return 0;
    }