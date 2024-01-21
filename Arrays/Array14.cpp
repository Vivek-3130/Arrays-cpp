#include<bits/stdc++.h>
using namespace std;

// vector<int> twoSum(vector<int> &a, int k) {
//     unordered_map<int, int> pairSum;
//     int n= a.size();
//     for (int i = 0; i < n; i++) {
//         int num = a[i];
//         int rem = k - num;
//         if (pairSum.find(rem) != pairSum.end()) {
//             return {pairSum[rem], i};
//         }
//         pairSum[num] = i;
//     }
//     return {-1, -1};
// }

vector<int> twoSum(vector<int> &nums, int k){
    vector<pair<int, int>> numsWithIndices;
    for (int i = 0; i < nums.size(); ++i) {
        numsWithIndices.push_back({nums[i], i});
    }

    // Sort the vector based on the elements
    sort(numsWithIndices.begin(), numsWithIndices.end(), 
        [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
        });

    int left = 0;
    int right = numsWithIndices.size() - 1;

    while (left < right) {
        int currentSum = numsWithIndices[left].first + numsWithIndices[right].first;
        
        // Check if the current pair of elements add up to the target sum
        if (currentSum == k) {
            // Return the indices of the two elements
            return {numsWithIndices[left].second, numsWithIndices[right].second};
        } else if (currentSum < k) {
            // Move the left pointer to a larger element
            left++;
        } else {
            // Move the right pointer to a smaller element
            right--;
        }
    }

    // If no such pair is found, return an empty vector
    return {};

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

    int k;
    cout << "Enter sum value of k: ";
    cin >> k;

    // Call the function and display the result
    vector<int> result = twoSum(a, k);

    if (result[0] != -1 && result[1] != -1) {
        cout << "Indices of the two numbers whose sum is equal to " << k << ": " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No such indices found." << endl;
    }

    return 0;
}
