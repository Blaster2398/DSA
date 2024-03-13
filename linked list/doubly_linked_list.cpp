#include<bits/stdc++.h>
using namespace std ;

struct node{
    int data;
    node* next;
    node* prev;

    node(int x){
        data= x;
        next=NULL;
        prev=NULL; 
    }
};

node* make_doubly_linked_list(int n);
void print(node* head);
node* insert_begin(node* head);
node* insert_at_end(node* head);
node* reverse(node* head);
node* delete_the_first(node* head);




int main(){
    int n;
    cin>>n;

    node* head=NULL;
    head=make_doubly_linked_list(n);
    print(head);
    // head= insert_begin(head);
    // print(head);
    // head= insert_at_end(head);
    // print(head);
    // head= reverse(head);
    // print(head);
    head=delete_the_first(head);
    print(head);


  return 0;
}

node* make_doubly_linked_list(int n){
    if(n==0){
        return  NULL;
    }
    int data;
    cin>>data;
    node* head =new node(data);
    node* temp = head;
    for(int i=0;i<n-1;i++){
        cin>>data;
        node* temp2 =new node(data);
        temp->next=temp2;
        temp2->prev=temp;
        temp=temp->next;

    }
    return head;

}

void print(node*head){
    if(head==NULL){
        cout<<"The linked list is empty"<<endl;
        return;
    }
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

node* insert_begin(node*head){
    int data;
    cin>>data;
    node* temp =new node(data);
    
    temp->next=head;
    if(head!=NULL){
        head->prev=temp;
    }
    return temp;
}

node* insert_at_end(node* head){
    int data;
    cin>>data;
    node* temp =new node(data);
    if(head==NULL){
        return temp;
    }
    node* temp2 =head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
    temp->prev=temp2;
    return head;
}

node* reverse(node*head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    node* temp =NULL; //this will be used to store the prevous of every node we visit 
    node* temp2 =head; // this will be used for traversal
    while(temp2!=NULL){
        temp = temp2->prev;
        temp2->prev = temp2->next;
        temp2->next = temp;
        temp2 = temp2->prev;   //cause we have changed the previous with next
    }
    return temp->prev;  //as temp will be storing the node that was initailly secondlast and after reversal it will bew thw 2nd node so its prev is the head

}

node* delete_the_first(node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    node* temp =head;
    head=head->next;
    head->prev=NULL;
    delete temp;
    return head;

}












