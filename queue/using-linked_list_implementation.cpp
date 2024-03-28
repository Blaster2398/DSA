#include<bits/stdc++.h>
using namespace std ;

struct node{
    int data;
    node *next;

    // a function to declare a node ( we used to do this using mallock)
    node(int x){
        data =x;
        next =NULL;
    } 
};

struct Queue{
    node* front , *rear;
    int size;
    Queue(){
        front = NULL;
        rear = NULL;
        size = 0;
    }
    void enque( int x){
        node *temp = new node(x);
        if(front = NULL){
            front = rear = temp;
            size++;
            return;
        }
        rear -> next = temp;
        rear = temp;
        size++;
    }

    void deque(){
        if( front == NULL){
            return;
        }
        node* temp = front;
        front = front -> next;
        if(front == NULL){
            rear = NULL;
        }
        delete temp;
        size--;
    }

};

int main(){
    
  return 0;
}