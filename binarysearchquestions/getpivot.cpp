#include<iostream>
using namespace std;

int main(){
    int n; 
    cin>>n; 
    int arr[10];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int s=0, e=n;
    while(s<e){
        int mid=s+ (e-s)/2;
        if(arr[0]<=arr[mid]){
            s=mid+1;
        }
        else 
            e=mid; 
    }
cout<<arr[s];

}