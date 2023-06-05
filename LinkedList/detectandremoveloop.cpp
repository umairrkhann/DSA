#include<iostream>
#include<map>
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



bool isCircular(Node *head){
    if(head==NULL){
        return head;
    }
   Node *temp=head;
   temp=temp->next;
   while(temp!=NULL && temp !=head){
    temp=temp->next;

   }
   if (temp==head){
    return true;
    
     return false;
    
   }
}

bool detectLoop(Node *head){
    if (head==NULL)
    return false;

    map<Node*,bool> visited;
    Node* temp=head;

    while(temp!=NULL){
        if(visited[temp]!=true){
            cout<<"Loop present at "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
 void display(Node* &head){
        Node* temp=head;
        while(temp!= NULL){
            cout<<temp->data<<" ";
            temp=temp->next; 
        }
        cout<<endl;
    }

Node *floydDetectloop(Node *head){
    if(head==NULL)
        return NULL;
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            }
        slow=slow->next;

        if(slow==fast){
            cout<<"Cycle present at "<<slow->data<<endl;
            return slow;
        }

    }
    return NULL;
}

Node *Startingnode(Node* head){
    if(head==NULL)
    return NULL;

    Node *intersection=floydDetectloop(head);
    Node *slow=head;
    while (slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;

    }
    return slow;
}

void removeLoop(Node* head){
    if (head==NULL){
        cout<<"No list present";
    }

    Node *Startofloop=Startingnode(head);
    Node *temp=Startofloop;

    while(temp->next!=Startofloop && temp!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;


}


int main(){
    
    Node* node1=new Node(10);

    Node* head= node1;
    Node* tail= node1;
    display(head);

    Insertattail(tail,12);
    display(head);
   // Insertathead(head,12);
    
    
   Insertattail(tail,15);
    
    //Insertathead(head,8);
    display(head);

    Insertattail(tail,22);
    display(head);

    //cout<<isCircular(head)<<endl;
    tail->next=head->next;

    
    cout<<"Head is at: "<<head->data<<endl;
    cout<<"Tail is at: "<<tail->data<<endl;
    
    // if(detectLoop(head)){
    //     cout<<"Loop is present"<<endl;
    // }
    // else{
    //     cout<<"Loop isnt present";
    // }

     if(floydDetectloop(head)!=NULL){
        cout<<"Loop is present"<<endl;
    }
    else{
        cout<<"Loop isnt present";
    }
    cout<<"Starting node "<<Startingnode(head)->data<<endl;

    removeLoop(head);
    display(head);
}