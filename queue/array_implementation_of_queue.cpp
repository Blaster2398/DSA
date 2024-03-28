#include<bits/stdc++.h>
using namespace std ;

struct Queue{
    int size, cap;
    int *arr;

    Queue(int c){
        cap = c;
        size = 0;
        arr = new int[cap];
    }
    bool isFull(){
        return (size == cap);
    }
    bool isEmpty(){
        return (size == 0);
    }
    void enque( int x){
        if(isFull()){return;}
        arr[size] = x;
        size++;
    }
    void deque(){
        if(isEmpty()){return;}
        for(int i =0; i < size-1;  i++){
            arr[i] = arr[i=1];
        }
        size--;
    }
    int getfront(){
        if(isEmpty()){return -1;}
        else{return 0;}
    }
    int getRear(){
        if(isEmpty()){return -1;}
        else{return arr[size-1];}
    }
};

int main(){
    Queue s(5);
    cout<<s.isEmpty()<<endl;
    s.enque(50);
    s.enque(20);
    s.enque(10);
    s.enque(6);
    s.enque(23);

    cout<<s.isFull()<<endl;
    cout<<s.getRear()<<endl;
    // here 0 is not pushed into the queue
    s.enque(0);
    cout<<s.getRear()<<endl;
    

  
}