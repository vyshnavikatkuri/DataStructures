package Stacks and queues;
class Node{
    int val;
    Node next;
    public Node(int val){
        this.val=val;
        next=null;
    }
}
class MyQueue{
    Node front,rear;
    int size=0;
    MyQueue(){
        front=null;
        rear=null;
    }
    void push(int data){
        Node newnode=new Node(data);
        if(rear==null) {
            rear=newnode;
            front=newnode;
        }
        else{
            rear.next=newnode;
            rear=newnode;
        }
        size++;
    }
    int pop(){
        if(size==0) return -1;
        int ele=front.val;
        if(size==1){
            front=null;rear=null;
        }else{
            front=front.next;
        }
        size--;
        return ele;
    }

}
public class Queueusingll {
    
}
