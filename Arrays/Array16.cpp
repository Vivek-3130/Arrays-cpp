#include<bits/stdc++.h>
using namespace std;

// Brute force method:-O(N^2)
// int findMajorityElement(vector<int>& nums) {
//     int n = nums.size();
    
//     for (int i = 0; i < n; ++i) {
//         int count = 1;
//         for (int j = i + 1; j < n; ++j) {
//             if (nums[i] == nums[j]) {
//                 count++;
//             }
//         }
//         if (count > abs(n / 2)) {
//             return nums[i];
//         }
//     }

//     return -1; // No majority element found
// }

// Optimal Solution:- O(N)
int findMajorityElement(const vector<int>& nums) {
    unordered_map<int, int> countMap;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        countMap[nums[i]]++;
        if (countMap[nums[i]] > abs(n / 2)) {
            return nums[i];
        }
    }

    return -1; // No majority element found
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
    cout<< findMajorityElement(a);
    
    return 0;
}