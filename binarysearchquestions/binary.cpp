#include <iostream>
using namespace std;

int binarysearch(int arr[10],int k, int num){
    int s=0; 
    int e=num;
   
   
    while(s<=e){
     int mid=(s+e)/2;
        if (arr[mid]==k)
            return mid;
        else if (arr[mid]>k)
            e=mid-1;
        else 
            s=mid+1;
    } return -1;
    
}

int main(){
   int a[10];int n;
    cout<<"\n Enter the number of elements";
    cin>>n;

   int key;
   for(int i=0; i<n; i++)
    cin>>a[i];
    cout<<"\n Which element has to be found?";
    cin>> key; 
    int index=binarysearch(a,key,n);
    cout<<"Element found at"<<index;
} 