#include<stdio.h>
using namespace std;
#include<iostream>
#define MAX 100
class Queue{
    int front,rear,currsize;
    int arr[MAX];
    Queue(){
        front=-1;
        rear=-1;
        currsize=0;
    }
    void enqueue(int x){
         if(currsize==MAX){
            cout<<"Queue is full";
            return;
         }
         if(rear==-1) {
            front=0;rear=0;
         }else{
            rear=(rear+1)%MAX;
            
         }
         arr[rear]=x;
         currsize++;
    }
    int dequeue(){
        if(currsize==0){
            cout<<"queue is underflow";
            return -1;
        }
        int ele=arr[front];
        if(currsize=1){
            front=-1;
            rear=-1;
        }
        else{front=(front+1)%MAX;}
        currsize--;
        return ele;
    }
    int topele(){
        if(currsize==0) return -1;
        return arr[rear];
    }
    int main(){
        Queue q;
        q.enqueue(2);
        q.enqueue(4);
        q.enqueue(3);
        q.dequeue();

    }
};