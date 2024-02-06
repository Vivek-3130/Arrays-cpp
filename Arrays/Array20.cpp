#include<bits/stdc++.h>
using namespace std;

// Function to swap two elements in an array
// void swap(int& a, int& b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// // Function to reverse a portion of the array
// void reverseArray(int arr[], int start, int end) {
//     while (start < end) {
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }
// }

//  Function to find the next permutation using a for loop
// void findNextPermutation(int arr[], int n) {
//     // Find the first element from the right that is smaller than its next element
//     int i;
//     for (i = n - 2; i >= 0; --i) {
//         if (arr[i] < arr[i + 1]) {
//             break;
//         }
//     }

//     // If no such element is found, the array is in descending order, so reverse it
//     if (i < 0) {
//         reverseArray(arr, 0, n - 1);
//         return;
//     }

//     // Find the smallest element to the right of arr[i] that is greater than arr[i]
//     int j;
//     for (j = n - 1; j > i; --j) {
//         if (arr[j] > arr[i]) {
//             break;
//         }
//     }

//     // Swap arr[i] and arr[j]
//     swap(arr[i], arr[j]);

//     // Reverse the elements to the right of arr[i]
//     reverseArray(arr, i + 1, n - 1);
// }

// int main() {
//     int nums[] = {1, 2, 3}; // Example input
//     int n = sizeof(nums) / sizeof(nums[0]);

//     // Output the next permutation
//     cout << "Original Permutation: ";
//     for (int i = 0; i < n; ++i) {
//         cout << nums[i] << " ";
//     }
//     cout <<endl;

//     findNextPermutation(nums, n);

//     cout << "Next Permutation: ";
// }

vector<int> nextPermutation(vector<int> &arr) {
    int n = arr.size();
    int index = -1;
    
    // find the breaking point from where it will get the next permutation
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            index = i;
            break;
        }
    }

    //Kuch nhi mila to
    if(index == -1) {
        reverse(arr.begin(),arr.end());
        return arr;
    }

    // from here we are finding the number just larger than the index value
    for (int i = n - 1; i >= index; i--) {
        if (arr[i] > arr[index]) {
            swap(arr[i], arr[index]);
            break;
        }
    }
    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    cout << "Enter the elements of array: ";
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Call the function and display the result
    cout <<"Next Permutation Is :";
    vector<int> result = nextPermutation(arr);
    for (auto it : result) {
        cout<< it << " ";
    }
    cout << endl;

    return 0;
}