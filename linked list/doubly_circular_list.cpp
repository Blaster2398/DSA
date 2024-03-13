//Billo Bagge Billeyan Da Ki Karegi
//Bagge - Bagge Billeyan Da Ki Karegi

#include<bits/stdc++.h>
using namespace std ;

struct node{
    int data;
    node* next;
    node* prev;

    node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

node* create(int n);
void print(node* head);
node* insertatHead(node* head);

int main(){
    int n;
    cin>>n;
    node* head =NULL;
    head = create(n);
    print(head);
    head = insertatHead(head);
    print(head);

    // dealocation of memory
    node* originalHead = head;

    while (head != NULL) {
    node *temp = head;
    head = head->next;

    if (head == originalHead) {
        // If you've reached the original head, break the loop
        break;
    }

    delete temp;
    }

    return 0;
}

node* create(int n){
    if(n==0){
        return NULL;
    }
    int data;
    cin>>data;
    node* head = new node(data);
    node* temp = head;
    for(int i=1;i<n;i++){
        cin>>data;
        node* temp2 = new node(data);
        temp->next = temp2;
        temp2->prev = temp;

        temp=temp2;
    }
    temp->next = head;
    head->prev = temp;
    return head;
}


void print(node* head) {
    if (head == NULL) {
        return;
    }
    node* originalHead = head;  // Save the original head
    cout << head->data << " ";
    for (node* i = head->next; i != originalHead; i = i->next) {
        cout << i->data << " ";
    }
    cout<<endl;
}


node* insertatHead(node* head){
    int data;
    cin>>data;
    node* temp = new node(data);
    if (head == NULL) {
        // If the list is empty, make the new node point to itself
        temp->next = temp;
        temp->prev = temp;
        head = temp;
    }
    else{
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
        head = temp;
        
    }
    return head;
}














