#include<bits/stdc++.h>

//Brute Force Approach :-O(n*n1) & O(n1)-for the result array
// std::vector<int> intersectedArray(int arr[],int arr1[],int n,int n1){
//     std::vector<int> result;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n1; ++j) {
//             if (arr[i] == arr1[j]) {
//                 result.push_back(arr[i]);
//                 break;  // Move to the next element in the first array
//             }
//         }
//     }
//     return result;
// }

// Optimal Solution:- O(n+n1) & O(n)
std::vector<int> intersectedArray(int arr[],int arr1[],int n,int n1){
    std::vector<int> ans;
    
    std::sort(arr, arr + n);
    std::sort(arr1, arr1 + n1);

    int i = 0, j = 0;

    while (i < n && j < n1) {
        if (arr[i] == arr1[j]) {
            ans.push_back(arr[i]);
            i++;
            j++;
        } else if (arr[i] < arr1[j]) {
            i++;
        } else {
            j++;
        }
    }
    return ans;
}


int main(){
 int n;
    std::cout << "Enter the size of first array: ";
    std::cin >> n;

    int arr[n];

    std::cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int n1;
    std::cout << "Enter the size of second array: ";
    std::cin >> n1;

    int arr1[n1];

    std::cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n1; i++) {
        std::cin >> arr1[i];
    }
    
    std::cout<<"The Intersected Array is: ";
    std::vector<int> result = intersectedArray(arr,arr1,n,n1);
    for (int num : result) {
        std::cout << num << " ";
    }
}