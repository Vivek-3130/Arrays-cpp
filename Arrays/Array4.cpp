#include <bits/stdc++.h>
using namespace std;

// // Remove the duplicates from the sorted arrays-brute force
// int removeDuplicates(int arr[],int n){
//     set<int> s;
//     int i=0;
//     for(auto it : s){
//         arr[i]=it;
//         i++;
//     }
//     return s.size();
//   set<int> s;
//   int i = 0; // Index to write unique elements to the array
//   for (int j = 0; j < n; j++) {
//     if (s.find(arr[j]) == s.end()) { // Check if element is not already in the set
//       s.insert(arr[j]); // Add element to the set
//       arr[i++] = arr[j]; // Copy element to the updated array
//     }
//   }
//   return s.size(); // Return the number of unique elements
// }

// int main(){
//     int n; 
//     cin>>n;
//     int arr[n];
//     for(int i=0;i < sizeof(arr)/sizeof(arr[0]);i++){
//         cin>>arr[i];
//     }
//     cout<<"Duplicated number removed :"<<removeDuplicates(arr,n)<<endl;
// }

vector<int> removeDuplicates(int arr[], int n) {
    vector<int> result;

    if (n == 0) {
        return result; // Empty vector for empty array
    }

    result.push_back(arr[0]); // Add the first element to the result vector

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            result.push_back(arr[i]);
        }
    }

    return result;
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

    vector<int> uniqueElements = removeDuplicates(arr, n);

    cout << "Unique elements in the array: ";
    for (int element : uniqueElements) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
