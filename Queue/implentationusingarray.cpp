#include<iostream>
#include<queue>
using namespace std;

class Queue{
    
    int *arr;
    int size;
    int front;
    int rear;
public:
    Queue( int size ){
        this->size=size;
        arr=new int[size];
        front=0;
        rear=0;
    }

    void enqueue(int data){
        if(rear==size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
            
        }
    }
    void dequeue(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
        }
        else{
            arr[front]=-1;
            front++;
            if(front==rear){
                front=0;
                rear=0;
            }
            
            }

        }
    

    void Front(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
        }
        else{
        cout<<"Front of the queue is: "<<arr[front]<<endl;
        }
    }
    bool isEmpty(){
        if(front==rear){
            return true;
        }
        else{
            return false;
        }
    }
    void display(){
        for(int i=0; i<size; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

};

int main(){
    Queue Q1(6);
    Q1.enqueue(10);
    Q1.enqueue(15);
    Q1.enqueue(18);
    Q1.enqueue(19);
    Q1.display();
    Q1.dequeue();
    Q1.dequeue();
    Q1.display();
    Q1.Front();
    Q1.isEmpty();
}