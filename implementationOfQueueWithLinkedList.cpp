#include<iostream>
using namespace std;
# define SIZE 5
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};
class Queue{
    Node* front;
    Node* rear;
    int s;
public:
    Queue(){
        front = rear = NULL;
        s = 0;
    }
    void push(int val){
        Node* newNode = new Node(val);
        if(rear == NULL){
            front = rear = newNode;
            cout<<val<<" inserted.\n";
            return;
        }
        rear->next = newNode;
        rear = newNode;
        cout<<val<<" inserted.\n";
        s++;
    }
    void pop(){
        if(front == NULL){
            cout<<"Queue is empty.";
            return;
        }
        Node* temp = front;
        cout<<temp->val<<" removed.\n";
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        delete temp;
        s--;
    }
    int frontE(){
        if(front == NULL){
            cout<<"Queue is empty.";
            return -1;
        }
        
        return front->val;
       
    }
    void display(){
        if(front == NULL){
            cout<<"Queue is empty.\n";
            return;
        }
        Node* temp = front;
        
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
        return;
    }
    int size_t(){
        return s+1;
    }
};
int main(){
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.size_t()<<endl;
    q.display();
    q.frontE();
    q.pop();
    cout<<q.frontE()<<endl;
    q.display();
    cout<<q.size_t()<<endl;

    return 0;
}
