// Importing Libraries
#include<iostream>
using namespace std;


void getdata(int arr[10][10], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }
    
}

void print(int arr[10][10], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Maxrowsum(int arr[10][10], int row, int col){
    int max=INT16_MIN;
    int RowIndex=-1;
    for(int i=0; i<row; i++){
        int sum=0;
        for(int j=0; j<col; j++){
            sum= sum+ arr[i][j];
        }
        if (max<sum){
            max=sum; 
            RowIndex=i;

        }
    
    }
    cout<<"The maximum sum is: "<<max<<endl;
    cout<<"The row Index is: "<<RowIndex;

}

int Search(int arr[10][10], int row, int col, int target){
     for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if (arr[i][j]==target){
                cout<<"Element found"<<endl;
                return i,j;
            }
          
        }
        
    }
}
int main(){
    int arr[10][10];
    int i, j;
    int target;
    
    cout<<"Enter the no of rows: "<<endl;
    cin>>i;
    cout<<"Enter the no of columns:  "<<endl;
    cin>>j; 
   
    getdata(arr,i,j);
    print(arr, i, j);
    Maxrowsum(arr,i,j);
    
    cout<<"\n Enter the element to be searched: "<<endl;
    cin>>target;
    int ans=0;
    Search(arr, i, j, target);
    

    
}