#include <iostream>
using namespace std;
// find the largest number in the given array
int largestNumber(int arr[],int n){
    int max = arr[0];
    for(int i =0;i<n;i++){
        if(arr[i] > max){
            max=arr[i];
        }
    }
    return max;
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i < sizeof(arr)/sizeof(arr[0]);i++){
        cin>>arr[i];
    }
    cout<<"The largest number is:"<<largestNumber(arr,n);
}


