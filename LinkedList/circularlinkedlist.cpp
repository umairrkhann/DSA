#include<iostream>
using namespace std;

class Node{
    public:
     int data;
     Node* next;
    
    Node(int data){
       
       this->data= data;
        this-> next= NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data: "<<value<<endl;
    }

};

void Insertattail(Node* &tail, int data, int element){
    
    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        temp->next=temp;
    }
    else{
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
    Node* temp=new Node(data);
    temp->next=curr->next;
    curr->next=temp;
    }

}

void deleteNode(Node* tail, int data){
    if (tail==NULL){
        cout<<"List is already empty"<<endl;
        return;
    }

else{
    Node* prev=tail;
    Node* curr=prev->next;

    while(curr->data!=data){
        prev=curr;
        curr= curr->next;
    }
    prev->next=curr->next;

    if (curr==prev){
        tail=NULL;
    }
    else if(tail==curr){
        tail=prev;
    }
    curr->next=NULL;
    delete curr; 
}

}
void display(Node* tail){
    Node* temp=tail;
    if (tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    
    cout<<endl;
}

int main(){
    
    Node* tail=NULL;
    
    Insertattail(tail,3,5);
    display(tail);
    
    Insertattail(tail,4,3);
    display(tail);

    Insertattail(tail,5,4);
    display(tail);

    Insertattail(tail,6,4);
    display(tail);

    deleteNode(tail,6);
    display(tail);

    deleteNode(tail,4);
    display(tail);

    deleteNode(tail,5);
    display(tail);

    deleteNode(tail,3);
    display(tail);
}