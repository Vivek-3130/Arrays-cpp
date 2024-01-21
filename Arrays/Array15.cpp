#include<bits/stdc++.h>
using namespace std;

//Brute method:- O(2N)
// vector<int> sort0s1s2s(vector<int> &arr){
//     int n  = arr.size();
//     int cnt0 = 0,cnt1=0,cnt2=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]==0){
//             cnt0+=1;
//         }
//         else if(arr[i]==1){
//             cnt1+=1;
//         }
//         else{
//             cnt2+=1;
//         }
//     }
//     for(int i =0;i<cnt0;i++){
//         arr[i]=0;
//     }
//     for(int i =cnt0;i<cnt0+cnt1;i++){
//         arr[i]=1;
//     }
//     for(int i =cnt0+cnt1;i<n;i++){
//         arr[i]=2;
//     }

//     return arr;
// }

//Optimal Solution:- O(N)-Dutch National Flag Algorithm
 vector<int> sort0s1s2s(vector<int> &arr){
    int n = arr.size();
    int low = 0, high = n-1, mid =0;
    for(int i=0;i<n;i++){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return arr;
 }

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements of the array separated by space: ";
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    // Call the function and display the result
   vector<int> result = sort0s1s2s(a);
   for(auto it = result.begin(); it != result.end(); ++it){
    cout << *it << " ";
   }


    return 0;
}
