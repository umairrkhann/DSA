#include<iostream>
using namespace std;

int squareroot(int n){
    int s=0;
    int e=n;
    int ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;
    if(mid * mid > n){
        e= mid-1;
    }
    else if (mid * mid <n){
        ans=mid;
        s=mid+1;
    }else //if (mid*mid== n){
        return mid;
    //}
    
    }return ans;
}
double moreprecision(int n, int precison, int Tempsoln){
    double factor=1;
    double ans=Tempsoln;
    for(double i=0; i<precison; i++){
        factor= factor/10;
        for(double j=ans; j*j<n; j=j+factor){
            ans=j;
        }
    } 
    return ans;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int tempsoln=squareroot(n);
    cout<<tempsoln;
   cout<<"\n Square root of a number is: "<<moreprecision(n,3,tempsoln);
    return 0;
}