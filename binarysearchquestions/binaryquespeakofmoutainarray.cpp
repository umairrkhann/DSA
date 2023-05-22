#include<iostream>
using namespace std;

int Peak(int arr[], int n){
    int s=0, e=n;
    int mid= s+ (e-s)/2;
    
    while (s<e){
    int mid= s+ (e-s)/2;
        if (arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else
            e=mid;
    }return s;

}


int main(){
    int arr[4]={0,10,5,2};

    cout<<Peak(arr, 4);
}