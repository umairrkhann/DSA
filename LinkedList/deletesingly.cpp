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
        int value= this->data;
        if(this->next!=NULL){
            
            delete next;
            this->next==NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
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
    
    void deleteNode(Node* &head, int position){
        
        if(position=1){
          Node* temp=head;
          head=head->next;
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
            prev->next=curr->next;
              curr->next=NULL;
                delete curr;
        }
        
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

    deleteNode(head,3);
    display(head);
}