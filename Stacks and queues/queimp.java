package Stacks and queues;

class MyQueue{
    private int arr[];
    private int front,rear,cursize,maxsize;
    public MyQueue(){
        arr=new int[20];
        front=-1;
        rear=-1;
        cursize=0;
        maxsize=20;
    }
    public void push(int val){
        if(cursize==maxsize) {
            System.out.println("stack overflow");
            return ;
        }
        if(rear==-1 && front==-1){
            rear=0;front=0;
        }
        else{rear=(rear+1)%maxsize;}
        arr[rear]=val;
        cursize++;
    }
    public int pop(){
        if(cursize==0) return -1;
        int ele=arr[front];
        if(cursize==1){
            front=-1;rear=-1;
        }else{
            front=(front+1)%maxsize;
        }
        cursize--;
        return ele;
    }
    public int front(){
        if(front==-1) return -1;
        return arr[front];
    }
    
}
public class queimp {
    
}
