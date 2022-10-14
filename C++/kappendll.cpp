#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int value){
    data =value;
    next=NULL;
    prev=NULL;
    }
};

void insertAtTail(node* &head, int value){

 node* n=new node(value);
    if(head==NULL){
        head=n;
        return;
    }
   
    node* temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }

   temp->next=n;
    n->prev=temp;
}

int length(node *head){
    int l=0;
   node* temp=head;
   while(temp!=NULL){
    l++;
    temp=temp->next;
   }
return l;
}

node* kAppend(node* head,int k){
    node* newhead;
    node* newtail;
    node* tail=head;
    int l=length(head);
    k=k%l;
    int count=1;
    while(tail->next!=NULL){
       if(count==l-k){
        newtail=tail;
       }
       if(count==l-k+1){
        newhead=tail;
       }
       tail=tail->next;
       count++;
    }
    newtail->next=NULL;
    tail->next=head;

    return newhead;
}
void display(node* head){

     node* temp =head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
   cout<<endl;
}

int main(){
    node* head=NULL;
    int arr[]={1,2,3,5,6,7};
    for(int i=0;i<6;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    node* newhead=kAppend(head,3);
    display(newhead);
}