#include<bits/stdc++.h>
using namespace std;


const int MAX_N = 100; // Adjust the size as needed

// int longestSubarrayWithSumK(const int nums[], int n, int k, int result[]) {
//     int maxLength = 0;

//     for (int i = 0; i < n; ++i) {
//         for (int j = i; j < n; ++j) {
//             int currentSum = 0;
//             for (int m = i; m <= j; ++m) {
//                 currentSum += nums[m];
//             }

//             if (currentSum == k && (j - i + 1) > maxLength) {
//                 maxLength = j - i + 1;
//                 for (int m = i; m <= j; ++m) {
//                     result[m - i] = nums[m];
//                 }
//             }
//         }
//     }

//     return maxLength;
// }

// OR

// int longestSubarrayWithSumK(const int nums[], int n, int k, int result[]) {
//     int maxLength = 0;
//     int start = 0;
//     int currentSum = 0;

//     for (int end = 0; end < n; ++end) {
//         currentSum += nums[end];

//         while (currentSum > k) {
//             currentSum -= nums[start];
//             start++;
//         }

//         if (currentSum == k && (end - start + 1) > maxLength) {
//             maxLength = end - start + 1;
//             for (int i = start; i <= end; ++i) {
//                 result[i - start] = nums[i];
//             }
//         }
//     }

//     return maxLength;
// }

// int main() {
//     int nums[] = {1, 2, 3, 4, 5, 6};
//     int n = sizeof(nums) / sizeof(nums[0]);
//     int k = 9;
//     int result[MAX_N];

//     int length = longestSubarrayWithSumK(nums, n, k, result);

//     cout << "Longest Subarray with Sum " << k << ": ";
//     for (int i = 0; i < length; ++i) {
//         cout << result[i] << " ";
//     }

//     return 0;
// }

// OR

//O(nlogn)
// pair<int, int> longestSubarrayForPositiveSum(vector<int> a,long long k){
//     map<long long, int> preSum;
//     long long sum = 0;
//     int maxLen = 0;
//     int startIndex=-1;

//     for(int i=0;i<a.size();i++){
//         sum+=a[i];
//         if(sum ==k ){
//             maxLen=max(maxLen,i+1);
//         }
//         long long rem = sum-k;
//         //that means present h
//         if(preSum.find(rem) != preSum.end())
//         {
//             int len = i -preSum[rem];
//             maxLen=max(maxLen,len);
//             startIndex=preSum[rem]+1;
//         }
//         //iska mtlb last ko point kr rha h
//         if(preSum.find(sum)==preSum.end())
//         {
//             preSum[sum]=i;
//         }
//     }
//     return make_pair(startIndex, startIndex + maxLen - 1);
// }


int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements of the array separated by space: ";
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    

    long long k;
    cout << "Enter the value of k: ";
    cin >> k;

    // Call the function and display the result
    pair<int, int> result = longestSubarrayForPositiveSum(a, k);
    cout << "Length of the longest subarray with a positive sum for k = " << k << ": " << result.second - result.first + 1 << endl;

    cout << "The subarray is: ";
    for (int i = result.first; i <= result.second; ++i) {
        cout << a[i] << " ";
    }
}