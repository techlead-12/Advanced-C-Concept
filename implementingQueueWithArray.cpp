#include<iostream>
using namespace std;
# define SIZE 5
class Queue{
    int arr[SIZE];
    int front;
    int rear;
public:
    Queue(){
        front = rear = -1;
    }
    void push(int val){
        if(rear == SIZE-1){
            cout<<"Queue is full.";
            return;
        }
        if(front == -1){
            front = 0;
        }
        rear++;
        arr[rear] = val;
        cout<<val<<" inserted.\n";
    }
    void pop(){
        if(front == -1 || front > rear){
            cout<<"Queue is empty.";
            return;
        }
        cout<<arr[front]<<" removed.\n";
        front++;
    }
    void frontE(){
        if(front == -1 || front > rear){
            cout<<"Queue is empty.";
            return;
        }
        cout<<"Top element: "<<arr[front]<<"\n";
    }
    void display(){
        if(front == -1 || front > rear){
            cout<<"Queue is empty.";
            return;
        }
        cout<<"Current elements: ";
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    q.frontE();
    q.pop();
    q.frontE();
    q.display();

    return 0;
}
