#include<bits/stdc++.h>
using namespace std ;

class kStacks{
    int *arr;   // Array of size n to store actual content to be stored in stacks
    int *top;   // Array of size k to store indexes of top elements of stacks
    int *next;  // Array of size n to store next entry in all stacks
                // and free list
    int n, k;
    int free; // To store beginning index of free list

public:
    kStack(int k, int n);
    void push(int x, int sn);
    int pop(int sn);
    bool isEmpty(int sn){
        return (top[sn] == -1);
    }
    // A utility function to check if there is space available
    bool isFull()   {  return (free == -1);  }
};

// here we are just initializing the 3 arrays and putting vales in them
kStacks::kStack(int k, int n){
    arr = new int[n];
    next = new int[n];
    top = new int[k];
    for(int i = 0; i <k; i++){
        top[i] = -1;
    }
    free = 0;
    for(int i = 0; i < n-1; i++){
        next[i] = i+1;
    }
    next[n] = -1;
}

// push operation 
void kStacks::push(int x, int sn){
    if (isFull())
    {
        cout << "\nStack Overflow\n";
        return;
    }

    int i = free;
    free = next[i];
    next[i] = top[sn];
    top[sn] = i;
    arr[i] = x;
}

int kStacks::pop(int sn){
    if (isEmpty(sn))
    {
        cout << "\nStack Underflow\n";
        return;
    }
    int i = top[sn];
    top[sn] = next[i];
    next[i] = free;
    free = i;
    return arr[i];
}


int main(){
  //copied 
  // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    kStacks ks(k, n);
 
    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
 
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
 
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
  return 0;
}