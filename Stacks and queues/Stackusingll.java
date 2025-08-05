package Stacks and queues;
class Node{
    int val;
    Node next;
    public Node(int val){
        this.val=val;
        next=null;
    }
}
class MyStack{
    Node head;
    int size=0;
    MyStack(){ head=null;}
    public void push(int data){
        Node newnode=new Node(data);
        if(head==null) head=newnode;
        else{
            newnode.next=head;
            head=newnode;
        }
        size++;
    }
    public int pop(){
        if(size==0) return -1;
        Node popped=head;
        head=head.next;
        size--;
        return popped.val;
    }
    public int peek(){
        if(size!=0) return head.val;
        return -1;
    }
    public boolean empty(){
        return size==0?true:false;
    }
}
public class Stackusingll {
    public static void main(String[] args) {
        MyStack st=new MyStack();
        st.push(6);
        st.push(7);
        st.pop();
    }
}
