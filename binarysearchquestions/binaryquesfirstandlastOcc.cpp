#include <iostream>
using namespace std;

int Firstocc(int arr[10], int n , int key){
    int s=0, e=n-1;
    int ans=-1;
   
    while(s<=e){
        int mid=(s+e)/2;
        if (arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else 
            s=mid+1;
    } return ans; 

}
int Secondocc(int arr[10], int n , int key){
    int s=0, e=n-1;
    int ans=-1;
   
    while(s<=e){
        int mid=(s+e)/2;
        if (arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else 
            s=mid+1;
    } return ans; 

}

int main(){
    int even[5]={1,2,2,3,5};
    int odd[6]={5,8,9,9,9,10};
    int index=Firstocc(even, 5, 2);
    int index1=Secondocc(odd, 6, 9);
    cout<<index;
    cout<<"\n" <<index1; 

}