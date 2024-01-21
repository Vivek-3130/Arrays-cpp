#include <iostream>

void rightRotate(int arr[], int n, int k) {
    if (n == 0 || k % n == 0) {
        return;  // No rotation needed for an empty array or when k is a multiple of n
    }

    k = k % n;  // Adjust k to be within the range of array size

    for (int i = 0; i < k; i++) {
        // Perform one rotation by moving the last element to the front
        int lastElement = arr[n - 1];
        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = lastElement;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int rotationAmount = 2;

    // Call rightRotate function
    rightRotate(arr, n, rotationAmount);

    // Print the rotated array
    std::cout << "Rotated array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
