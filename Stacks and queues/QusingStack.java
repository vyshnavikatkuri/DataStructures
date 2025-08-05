import java.util.*;
class MyQueue {
    Stack<Integer>st1=new Stack<>();
    Stack<Integer>st2=new Stack<>();
    public MyQueue() {
        
    }
    
    public void push(int x) {
        while(!st1.isEmpty()){
            int ele=st1.peek();
            st1.pop();
            st2.push(ele);
        }
        st1.push(x);
        while(!st2.isEmpty()){
            int ele=st2.peek();
            st2.pop();
            st1.push(ele);
        }
    }
    
    public int pop() {
        if(st1.isEmpty()) return -1;
        int ele=st1.peek();
        st1.pop();
        return ele;
    }
    
    public int peek() {
        if(st1.isEmpty()) return -1;
        return st1.peek();
    }
    
    public boolean empty() {
        return st1.isEmpty()?true:false;
    }
}
public class QusingStack{
    public static void main(String[] args) {
        
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */