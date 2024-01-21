#include<bits/stdc++.h>
using namespace std;


void leftRotate(int* arr, int n, int d) {
    if (n == 0 || d % n == 0) {
        return;  // No rotation needed for an empty array or when d is a multiple of n
    }

    d = d % n;  // Adjust d to be within the range of array size

    for (int i = 0; i < d; i++) {
        // Perform one rotation by moving the first element to the end
        int firstElement = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = firstElement;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int rotateCount = 2;

    // Call leftRotate function
    leftRotate(arr, n, rotateCount);

    // Print the rotated array
    std::cout << "Rotated array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}


// int main() {
//     int n;
//     cout << "Enter the size of the array: ";
//     cin >> n;

//     int arr[n];
//     int rotateCount =1;

//     cout << "Enter the elements of the array: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];~
//     }

//     vector<int> uniqueElements = leftRotate(arr, n, rotateCount);

//     cout << "Left Rotated Array is: ";
//     for (int element : uniqueElements) {
//         cout << element << " ";
//     }
//     cout << endl;

//     return 0;
// } 


// #include<bits/stdc++.h>
// using namespace std;

// vector<int> leftRotate(vector<int>& arr,int n,int rotateCount){
//     vector<int> op;

//     while(rotateCount--) {
//         int temp = arr[0];
//         for(auto it = arr.begin()+1; it != arr.end(); it++) {
//             op.push_back(*it);
//         }
//         op.push_back(temp);
//     }
//     return op;
// }

// int main() {
//     int n;
//     cout << "Enter the size of the array: ";
//     cin >> n;

//     vector<int> arr(n);
//     int rotateCount =1;

//     cout << "Enter the elements of the array: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     vector<int> uniqueElements = leftRotate(arr, n, rotateCount);

//     cout << "Left Rotated Array is: ";
//     for (int element : uniqueElements) {
//         cout << element << " ";
//     }
//     cout << endl;

//     return 0;
// } 

//optimal sol

// vector<int> leftRotate(vector<int> &arr, int n, int d) {
//     d = d % n; // remainder times rotate -> actual count
//     if (d == 0) {
//         return arr;
//     }

//     vector<int> vect(d);

//     for (int i = 0; i < d; i++) {
//         vect[i] = arr[i];
//     }

//     for (int i = d; i < n; i++) {
//         arr[i - d] = arr[i];
//     }

//     for (int i = n - d, j = 0; i < n; i++, j++) {
//         arr[i] = vect[j];
//     }

//     return arr;
// }

// most optimised with O(2d) tc but O(1) sc
// vector<int> leftRotate(vector<int> &arr, int n, int d){
//     d=d%n;
//     reverse(arr.begin(),arr.begin()+d);
//     reverse(arr.begin()+d,arr.end());
//     reverse(arr.begin(),arr.end());
//     return arr;
// }

// int main() {
//     int n;
//     cout << "Enter the size of the array: ";
//     cin >> n;

//     vector<int> arr(n);
//     int rotateCount;
//     cout<<"Enter the rotated count: ";
//     cin>>rotateCount;

//     cout << "Enter the elements of the array: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     vector<int> uniqueElements = leftRotate(arr, n, rotateCount);

//     cout << "Left Rotated Array is: ";
//     for (int element : uniqueElements) {
//         cout << element << " ";
//     }
//     cout << endl;

//     return 0;
// }