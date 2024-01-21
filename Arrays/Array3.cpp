#include<iostream>
using namespace std;
// The given array is sorted or not?
int sorted(int arr[],int n){
    if (n == 1) return true;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

int main(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0;i < sizeof(arr)/sizeof(arr[0]);i++){
        cin>>arr[i];
    }
    cout<<"The given is sorted or not :"<<sorted(arr,n)<<endl;
}