#include <bits/stdc++.h>
using namespace std;
// Find the second largest & smallest number
//Optimal Solution:- non-negative number
int secondLargestNumber(int arr[],int n)
{
    int largest= arr[0];
    int secondLargest=-1;
    for(int i =1;i<n;i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest=arr[i];
        }
        else if(arr[i] < largest && arr[i] > secondLargest){
            secondLargest=arr[i];
        }
    }
    return secondLargest;

}

int secondsmallestNumber(int arr[],int n){
    int smallest = arr[0];
    int secondSmallest = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            secondSmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]<secondSmallest && arr[i]!= smallest){
            secondSmallest=arr[i];
        }
    }
    return secondSmallest;

}


//Better Solution
// int secondLargestNumber(int arr[],int n){
//     int largest= arr[0];
//     int secondLargest=-1; //assuming every element in the array is positive and INT_MIN if negativ element is present
//     for(int i=0;i<n;i++){
//         if(arr[i]>largest) largest = arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i]>secondLargest && arr[i]!= largest) secondLargest=arr[i];
//     }
//     return secondLargest;
// }


int main(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0;i < sizeof(arr)/sizeof(arr[0]);i++){
        cin>>arr[i];
    }
    cout<<"The second largest number is:"<<secondLargestNumber(arr,n)<<endl;
    cout<<"The second smallest number is:"<<secondsmallestNumber(arr,n);
}