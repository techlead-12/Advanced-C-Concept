#include<iostream>
#include<algorithm>
using namespace std;
class MinHeap{
public:
    int arr[50];
    int idx;
    MinHeap(){
        this->idx = 1;
    }
    int top(){
        return arr[1];
    }
    void push(int val){
        arr[idx] = val;
        int i = idx;
        idx++;
        while(i > 1){
            if(arr[i] < arr[i/2]){
                swap(arr[i],arr[i/2]);
            }
            else{
                break;
            }
            i = i/2;
        }
    }
    void pop(){
         idx--;
         arr[1] = arr[idx];
         int i =1;
         while(true){
             int l = 2*i;
             int r = 2*i +1;
             if(l > idx-1){
                 break;
             }
             if(r > idx-1){
                 if(arr[l] < arr[i]){
                     swap(arr[l],arr[i]);
                     i = l;
                 }
                 break;
             }
             
             int x = min(l,r);
             if(arr[i] > arr[x]){
                swap(arr[x],arr[i]);
                i = x;
             }
             else{
                 break;
             }
         }
    }
    int size(){
        return idx-1;
    }    
    void display(){
        for(int i=1;i<idx;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
      MinHeap pq;
      pq.push(10);
      pq.push(20);
      pq.push(11);
      cout<<"Size = "<<pq.size();
      cout<<endl;
      cout<<"Minimum Element: "<<pq.top();
      pq.push(2);
      cout<<endl;
       cout<<"Size = "<<pq.size();
      cout<<endl;
      cout<<"Minimum Element: "<<pq.top();
      pq.pop();
      cout<<endl;
      cout<<"Minimum Element: "<<pq.top();
      cout<<endl<<pq.size();
    return 0;
}
