#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){
    int Studentcount=1;
    int Pagesum=0;
    for(int i=0; i<n; i++){
        if(Pagesum +arr[i]<=mid){
            Pagesum+=arr[i];
        }
        else 
        {
            Studentcount++;
            if(Studentcount > m || arr[i]>mid){
                return false; 
            }
        Pagesum=arr[i];
        }
    }return true;
}
int allocatebooks(int arr[], int n , int m){
    int s=0;
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=arr[i];
    int e=sum; 
    int mid= s+ (e-s)/2;
    int ans=0;
     while(s<=e){
        int mid= s+ (e-s)/2;
         if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
         }
         else 
         s=mid+1;
     }return ans;
}

int main(){
    int arr[]={10,20,30,40};
    int ans = allocatebooks(arr,4,2);
    cout<<ans;

}