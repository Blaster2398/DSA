#include<bits/stdc++.h>
using namespace std ;

struct node{
    int data;
    node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};

struct myStack{
    node* head;
    int sz;
    myStack(){
        head = NULL;
        sz = 0;
    }
    void push(int x){
        node* temp = new node(x);
        temp -> next = head;
        head = temp;
        sz++;
    }
    int pop(){
        if( head == NULL ){
            return INT_MAX;
        }
        int res = head -> data;
        node* temp = head;
        head = head -> next;
        delete(temp);
        sz--;
        return res;
    }
    int size(){
        return sz;
    }
    // this will check is head value is equal to null 
    bool isEmpty(){
        return (head == NULL);
    }
    int peek(){
        if( head == NULL ){
            return INT_MAX;
        }
        return head -> data;
    }
};


int main(){
    myStack s;
    s.push(5);
    s.push(10);
    s.push(20);

    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.pop()<<endl;

  return 0;
}