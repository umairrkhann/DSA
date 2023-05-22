#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    int s=0; 
    int e=n-1;

    while (s<e){
        int mid=s+(e-s)/2;

        if (mid*mid>n){
            e=mid-1;
        }
        else if(mid*mid<n){
            s=mid+1;
        }
        else{
            ans=mid;
             break;
        }
    
    } 
    cout<<ans; 
    return 0;
}