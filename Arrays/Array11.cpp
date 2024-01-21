#include <bits/stdc++.h>

// Brute: O(n^2) & O(1)
// int missingNumber(int arr[], int n) {
//     for (int i = 1; i <= n; i++) {
//         int flag = 0;
//         for (int j = 0; j < n; j++) {
//             if (arr[j] == i) {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 0)
//             return i;
//     }
// }

// Optimised Soln1
// int missingNumber(int arr[], int n) {
//     // Calculate the expected sum of the first n natural numbers
//     int expectedSum = n * (n + 1) / 2;

//     // Calculate the actual sum of array elements
//     int actualSum = 0;
//     for (int i = 0; i < n; i++) {
//         actualSum += arr[i];
//     }

//     // The missing number is the difference between the expected and actual sums
//     return expectedSum - actualSum;
// }

// Optimised Soln2
// int missingNumber(int arr[], int n) {
//     // Create a hash set to store the elements
//     std::unordered_set<int> hashSet;

//     // Insert all elements into the hash set
//     for (int i = 0; i < n; i++) {
//         hashSet.insert(arr[i]);
//     }

//     // Check for the missing number by iterating from 1 to n
//     for (int i = 1; i <= n; i++) {
//         if (hashSet.find(i) == hashSet.end()) {
//             return i;
//         }
//     }

//     // If no missing number is found, return n+1
//     return n + 1;
// }

// Optimised Soln3
int missingNumber(int arr[], int n) {
    // XOR all numbers from 1 to n
    int xorAll = 0;
    for (int i = 1; i <= n; i++) {
        xorAll ^= i;
    }

    // XOR all elements in the array
    for (int i = 0; i < n; i++) {
        xorAll ^= arr[i];
    }

    return xorAll;
}

int main() {
    int n;
    std::cout << "Enter the size of array: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "The missing number in the array is: " << missingNumber(arr, n) << std::endl;
    return 0;
}
