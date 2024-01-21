#include <iostream>
#include <set>


//Brute Force Method:-
//TC= O(nlogn)+O(n1logn)+O(n+n1)
//SC= O(n+n1) + O(n+n1)(for returning)

// std::set<int> unionArray(int arr[], int arr1[], int n, int n1) {
//     std::set<int> unionSet;

//     // Insert elements from the first array
//     for (int i = 0; i < n; i++) {
//         unionSet.insert(arr[i]);
//     }

//     // Insert elements from the second array
//     for (int i = 0; i < n1; i++) {
//         unionSet.insert(arr1[i]);
//     }

//     return unionSet;
// }


// Optimal Solution:-
//TC = O(n+n1)
//SC = O(n+n1)(for returning)

std::set<int> unionArray(int arr[], int arr1[], int n, int n1) {
    std::set<int> unionSet;
    int i = 0, j = 0;

    while (i < n && j < n1) {
        if (arr[i] < arr1[j]) {
            unionSet.insert(arr[i]);
            i++;
        } 
        else if (arr[i] > arr1[j]) {
            unionSet.insert(arr1[j]);
            j++;
        } 
        else {
            unionSet.insert(arr[i]);
            i++;
            j++;
        }
    }

    // Insert remaining elements from the first array
    while (i < n) {
        unionSet.insert(arr[i]);
        i++;
    }

    // Insert remaining elements from the second array
    while (j < n1) {
        unionSet.insert(arr1[j]);
        j++;
    }

    return unionSet;
}


int main() {
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

    std::set<int> result = unionArray(arr, arr1, n, n1);

    std::cout << "Union Array is: ";
    for (const auto &element : result) {
        std::cout << element << " ";
    }

    return 0;
}
