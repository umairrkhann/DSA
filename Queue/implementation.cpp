#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<int> q;

    q.push(10);
    q.push(11);
    q.push(13);

    cout<<"The size of the queue is: "<<q.size()<<endl;
    cout<<"Front of queue is: "<<q.front()<<endl;
    q.pop();
    q.pop();
    cout<<"The back of the queue: "<<q.back()<<endl;
    cout<<"Front of queue is: "<<q.front()<<endl;;
    cout<<"The size of the queue is: "<<q.size()<<endl;
    q.pop();
    cout<<"Front of queue is: "<<q.front()<<endl;
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
}

