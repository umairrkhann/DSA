#include<iostream>
#include<vector>

using namespace std;
 
 vector<int> rotate(vector<int> v, int n){
    
    vector<int> temp(v.size());
    for(int i=0; i< v.size(); i++){
        temp[(i+n)%v.size()]=v[i];
    }
    v=temp;
    return v;
 }
 void print(vector<int> v){
    for(int i=0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
}
 int main(){
    vector <int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(5);
    vector <int> ans= rotate(v,2);
   
    print (ans);
 }