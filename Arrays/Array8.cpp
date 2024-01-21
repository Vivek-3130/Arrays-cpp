#include <iostream>

std::pair<int, int> linearSearch(int arr[], int n, int s) {
    int count = 0;
    int last_index = -1;  // Initialize to -1, indicating not found

    for (int i = 0; i < n; i++) {
        if (arr[i] == s) {
            count++;
            last_index = i;
        }
    }

    return std::make_pair(count, last_index);
}

int main() {
    int n;
    std::cout << "Enter the size of array: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Insert The Element Into The Array:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "The Array You Inserted Is:\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int s;
    std::cout << "Enter The Element You Want To Search: ";
    std::cin >> s;

    auto result = linearSearch(arr, n, s);

    std::cout << "The Element Is " << result.first << " Times Present In The Given Array\n";
    if (result.second != -1) {
        std::cout << "The Element Is Present At Index: " << result.second << std::endl;
    } else {
        std::cout << "The Element is not found in the array.\n";
    }

    return 0;
}
