//Billo Bagge Billeyan Da Ki Karegi
//Bagge - Bagge Billeyan Da Ki Karegi

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

// delclarations of the functions used 
node* create( int n );
void print(node*head);
void printR(node* head);
node* insert_at_0(node* head);
node* insert_at_end(node* head );
node* delete_the_first(node* head);
node* delete_the_last(node* head);
node* insert_at_i(node *head);
auto findR(node* head, int);
int findi(node* head);


int main(){
    
    int n;
    cin>>n;
    node* head=NULL;
    head=create(n);
    
    print(head);

    // head= insert_at_end(head);
    // head= insert_at_0(head);
    // head=delete_the_first(head);
    // head =delete_the_last(head);
    // head= insert_at_i(head);
    int z=findi(head);
    cout<<z<<endl;

    printR(head);

    cout<<"done with the process"<<endl;


    // Deallocate memory
    while (head != NULL) {
        node *temp = head;
        head = head->next;
        delete temp;
    }


    return 0;
}

// we always use a new keyword before making a node dynamically allocating space
//function to create a linked list when number of links are given /elements are given
node* create( int n ){
    if(n==0){
        return NULL;
    }
    int data;
    cin>>data;
    node *head =new node(data);
    node *temp =head;
    for(int i=0;i<n-1;i++){
        int data;
        cin>>data;
        node *temp2 =new node(data);
        temp->next =temp2;
        temp=temp2;
    }
    return head;
}

//function to print the node using iteration 
// time ->O(n) but the space is O(1) doesn't  take any extra space 
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

// function to print the linked list using recursion 
// time ->O(n)   and space ->O(n) due tp the space taken by the function call 
void printR(node* head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    printR(head->next);
}

// this code will insert the nodes in the begining 
// time and space complexity is O(1)
node* insert_at_0(node* head){
    int data ;
    cin>>data;
    node*temp =new node(data);
    if(head==NULL){
        return temp;
    }
    temp->next=head;
    head=temp;

    return head;
}

// this code appends a new linked list at the end 
// time complexity = O(n) space = O(1)
node* insert_at_end(node* head ){
    int data ;
    cin>>data;
    node* temp2 = head;
    node* temp =new node(data);
    if(head==NULL){
        return temp;
    }

    while(temp2->next!=NULL){
        temp2= temp2->next;
    }
    temp2->next=temp;
    return head;
}

//deletion of the first node ;
// time and space = O(1)
node* delete_the_first(node* head){
    if(head==NULL){
        return NULL;
    }
    node* temp = head->next;
    delete head;                      // this will dealocate the memory 
    return temp;
}

//to delete the last node 
// time= O(n)
node* delete_the_last(node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete head ;
        return NULL;
    }
    node* temp= head;
    
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}

//to insert at i'th index 
node* insert_at_i(node* head ){
    int id,data;
    cin>>id>>data;
    node* temp = new node(data);
    //this will handel the case when the id ==1
    if(id==1){
        temp->next=head;
        return temp;

    }
    node* temp2 = head;
    for(int i=1;(i<id-1);i++){
        temp2=temp2->next;
    }
    //this is to handel id>> size of linked list
    if(temp2==NULL){
        return head;
    }
    temp->next=temp2->next;
    temp2->next=temp;

    return head;

}
    
// to find a element in a linked list with reccursion
auto findR(node* head, int data){
    if(head==NULL){
        return -1;
    }

    if(head->data==data){
        return 1;
    }

    else{
        int res=findR(head->next,data);
        if(res==-1){
            return -1;
        }
        else{
            return res+1;
        }
    }
}

int findi(node* head){
    int data;
    cin>>data;
    int pos = 1;
    node* temp =head;
    while(temp!=NULL){
        if(temp->data==data){
            return pos;
        }
        else{
            pos++;
            temp=temp->next;
        }
    }
    return -1;

}


























































