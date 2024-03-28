#include<bits/stdc++.h>
using namespace std ;

//circular implementation of the dequeue where the functions are 
// insert_front , insert_rear, delete_front, delete_rear
struct Deque{
    int* arr;
    int size, front, cap;

    Deque(int x){
        arr = new int[x];
        cap = x;
        front = 0;
        size = 0;
    }
    // Check if the queue is full
    bool isFull() {
        return (size == cap);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (size == 0);
    }
    int getFront(){
        if(isEmpty()){return -1;}
        else{return arr[front];}
    }
    int getRear(){
        if(isEmpty()){return -1;}
        else{return arr[(front + size - 1) % cap];}
    }
    void deleteFront(){
        if(isEmpty()){return;}
        front = (front + 1) % cap;
        size--;
    }
    void deleteRear(){
        if(isEmpty()){return;}
        size--;
    }
    void insertFront(int x){
        if(isFull()){return;}
        front = (front - 1 + cap) % cap;
        arr[front] = x;
        size++;
    }
    void insertRear(int x){
        if(isFull()){return;}
        int new_rear = (front+ size) % cap;
        arr[new_rear] = x;
        size++;
    }

};
int main(){
    Deque dq(5);
    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertRear(30);
    cout<<dq.getFront()<<endl;
    cout<<dq.getRear()<<endl;
    dq.deleteFront();
    cout<<dq.getFront()<<endl;
  return 0;
}