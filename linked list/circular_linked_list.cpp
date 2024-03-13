//Billo Bagge Billeyan Da Ki Karegi
//Bagge - Bagge Billeyan Da Ki Karegi

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

node* create(int n);
void print(node*head);
void printdw(node* head);
node* insertatBegin(node* head);
node* insertatEnd(node* head);
node* deletehead(node* head);
node* deleteKth(node* head);

int main(){

    int n;
    cin>>n;
    node* head=NULL;
    head = create(n);
    printdw(head);
    // head=insertatBegin(head);
    // print(head);
    // head = insertatEnd(head);
    // printdw(head);
    // head = deletehead(head);
    // print(head);
    head = deleteKth(head);
    print(head);


    // // Deallocate memory
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
        temp->next=temp2;
        temp=temp2;
    }
    temp->next=head;
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


void printdw(node* head){
    if(head==NULL){
        return;
    }
    node* i =head;
    do{
        cout<<(i->data)<<' ';
        i=i->next;
    }while(i!=head);
    cout<<endl;
}


node* insertatBegin(node* head){
    int data;
    cin>>data;
    node* temp= new node(data);
    if(head == NULL){
        temp->next=temp;
        return temp;
    }
    else{
        node* temp2=head;
        while(temp2->next!=head){
            temp2=temp2->next;
        }
        temp2->next=temp;
        temp->next=head;
        head=temp;
    }
    return head;
}  

node* insertatEnd(node* head){
    int data;
    cin>>data;
    node* temp= new node(data);
    if(head == NULL){
        temp->next=temp;
        return temp;
    }
    else{
        node* temp2=head;
        while(temp2->next!=head){
            temp2=temp2->next;
        }
        temp2->next=temp;
        temp->next=head;
    }
    return head;
}

node* deletehead(node* head){
    if(head == NULL || head->next == head){     // here we have to give this condition as in single element it is connected to itself 
        return NULL;
    }
    node* temp = head;
    head = head->next;
    node* temp2 =head;
    while(temp2->next != temp){
        temp2 = temp2->next;
    }
    temp2->next = head; 
    delete temp;
    return head;
}

node* deleteKth(node* head){
    int data;
    cout<<"which element you want to delete ";
    cin>>data;
    if(data == 1){
        return deletehead(head);
    }
    else{    
        node* temp = head;
        // the case when no of elements are less than the data provided 
        for(int i =0 ;i < data-2 ; i++){
            temp = temp->next;
        }
        node* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        return head;
    }
}













