#include<bits/stdc++.h>
using namespace std ;

struct twoStacks{
    int *arr;
    int cap, top1, top2;
    twoStacks(int n){
        top1 = -1;
        top2 = n;
        cap = n;
        arr = new int[n];
    }
    void push1(int x){
        if(top1 < top2-1){
            top1++;
            arr[top1] = x;
        }
    }

    void push2(int x){
        if(top1 < top2-1){
            top2--;
            arr[top2] = x;
        }
    }
    int pop1(){
       if(top1 > -1){
        int x = arr[top1];
        top1--;
        return x;
       }
       else{
        cout<<"Underflow"<<endl;
        exit(1);
    }
    }
    int pop2(){
       if(top2 < cap){
        int x = arr[top2];
        top2++;
        return x;
       }
       else{
        cout<<"Underflow"<<endl;
        exit(1);
       }
    }
};

int main() {
  // Create a twoStacks object with capacity 5
  twoStacks stk(5);

  // Push elements to stack 1
  stk.push1(5);
  stk.push1(10);
  stk.push1(20);

  // Push elements to stack 2
  stk.push2(15);
  stk.push2(20);

  // Pop elements from stack 1
  cout << "Popped element from stack 1: " << stk.pop1() << endl; // Output: 10
  cout << "Popped element from stack 1: " << stk.pop1() << endl; // Output: 5
  cout << "Popped element from stack 1: " << stk.pop1() << endl; // Output: Program exits due to underflow

  // Pop elements from stack 2
  cout << "Popped element from stack 2: " << stk.pop2() << endl; // Output: 20
  cout << "Popped element from stack 2: " << stk.pop2() << endl; // Output: 15

  // Pop element from stack 2 (underflow)
  cout << "Popped element from stack 2: " << stk.pop2() << endl; // Output: Program exits due to underflow

  return 0;
}
