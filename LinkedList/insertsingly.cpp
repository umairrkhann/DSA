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

};
    
    void Insertathead(Node* &head, int data){
        Node* temp=new Node(data);
        temp->data=data;
        temp->next=head; 
        
        head=temp;
    }

    void Insertattail(Node* &tail, int data){
        Node* temp=new Node(data);
        tail->next= temp;
        tail=temp;
    }

    void Insertatmiddle(Node* &head, Node* &tail,int position, int data){
        Node* temp= head;
        int cnt=1;
        if (position==1){
            Insertathead(head,data);
            return;
        }

        if(temp->next==NULL){
            Insertattail(tail,data);
            return;
        }
        
        while(cnt<position-1){
            temp=temp->next;
            cnt++;
        }

        Node* NodetobeInserted= new Node(data);
        NodetobeInserted->next=temp->next;
        temp->next=NodetobeInserted;

    }

    void display(Node* &head){
        Node* temp=head;
        while(temp!= NULL){
            cout<<temp->data<<" ";
            temp=temp->next; 
        }
        cout<<endl;
    }


int main(){
    
    Node* node1=new Node(15);

    Node* head= node1;
    Node* tail= node1;
    display(head);

    Insertattail(tail,12);
    display(head);
   // Insertathead(head,12);
    
    
   Insertattail(tail,8);
    
    //Insertathead(head,8);
    display(head);

    Insertatmiddle(head,tail,4,9);
    display(head);
}