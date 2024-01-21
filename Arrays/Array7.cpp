#include <bits/stdc++.h>
using namespace std;


// Brute Approach
// void moveZerosToEnd(int arr[], int n) {
//     vector<int> vect(n);
//     // int nonZeroIndex = 0;

//     for (int i = 0; i < n; i++) {
//         if (arr[i] != 0) {
//             vect[nonZeroIndex++] = arr[i];
//         }
//     }

//     // Fill the remaining elements with zeros
//     // while (nonZeroIndex < n) {
//     //     vect[nonZeroIndex++] = 0;
//     // }
//     int nz = temp.size();
//     for(int i =nz;i<n;i++){
//         arr[i]=0;
//     }

//     // Copy the modified vector back to the original array
//     for (int i = 0; i < n; i++) {
//         arr[i] = vect[i];
//     }
// }

// Optimised Solution:- here the space complexity is O(1)
void moveZerosToEnd(int arr[], int n){
    int j=-1;
    if(j==-1) return arr;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call moveZerosToEnd function
    moveZerosToEnd(arr, n);

    // Print the modified array
    cout << "Array after moving zeros to the end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
