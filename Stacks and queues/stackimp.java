package Stacks and queues;
import java.util.*;
class MyStack{
    int size=10000;
    int arr[]=new int[size];
    int top=-1;
    void push(int val){
        if(top==size-1) {
            System.out.println("Stack overflow");return;}
        arr[++top]=val;
        return;
    }
    int pop(){
        if(top==-1) {
            System.out.println("stack empty");
            return -1;
        }
        int ele=arr[top];
        top--;
        return ele;
    }
    int top(){
        return arr[top];
    }
    int size(){
        return top+1;
    }
}
public class stackimp {
    public static void main(String[] args) {
        MyStack s=new MyStack();
        s.push(2);
        s.pop();
    }
}
