#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        int value=this->data;
        if (next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory is free for node with value "<<value<<endl;
    }
}; 
void Insertathead(Node* &head, int d){
    
    Node* temp=new Node(d); 
    temp->next=head;
    head->prev=temp;
    head=temp;
    }


void Insertattail(Node* &tail, int d){
    
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }


void Insertatmiddle(Node* &head, Node* &tail, int position, int d){
     
     if (position==1){
        Insertathead(head,d);
        return;
     }
     
     int cnt=1;
     Node* temp=head;
     
     while(cnt<position-1){
        temp=temp->next;
        cnt++;
     } 
     

    Node* NodetoInsert=new Node(d);
     NodetoInsert->next=temp->next;
     temp->next->prev=NodetoInsert;
     temp->next=NodetoInsert;
     NodetoInsert->prev=temp;

     if(temp->next==NULL){
        Insertattail(tail,d);
        return;
     }
}
void deleteNode(Node* head, int position){
    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* prev=NULL;
        Node* curr=head;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1=new Node(10);
    Node* head=node1; 
    Node* tail=node1; 
    display(head);
   Insertathead(head,12);
    display(head);
    Insertattail(tail,20);
    display(head);
    Insertatmiddle(head,tail,3,15);
    display(head);
    deleteNode(head,4);
    display(head);
}