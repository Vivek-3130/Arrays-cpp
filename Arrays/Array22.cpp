#include <bits/stdc++.h>
using namespace std;

// Brute force : O{N^2}
// int longestConsecutiveSequence(vector<int> &arr) {
//     int n = arr.size();
//     if (n == 0) {
//         return 0;
//     }

//     int longest = 1;

//     for (int i = 0; i < n; i++) {
//         int currentNum = arr[i];
//         int currentStreak = 1;

//         // Check for consecutive numbers in increasing order
//         //apan idhar currentelewment stored jo hai uske agla numbwr dudh rahe hai consecutive hai ya nhi
//         while (find(arr.begin(), arr.end(), currentNum + 1) != arr.end()) {
//             currentNum++;
//             currentStreak++;
//         }

//         longest = max(longest, currentStreak);
//     }

//     return longest;
// }

// Better Solution:but here there will be o(nlogn)+o(n)
// int longestConsecutiveSequence(vector<int> &arr) {
//     int n = arr.size();
//     int longest = 1; // Initialize to 1 for the single element itself
//     int curr_count = 1;

//     sort(arr.begin(), arr.end());

//     for (int i = 1; i < n; ++i) {
//         if (arr[i] == arr[i - 1]) {
//             // Skip duplicates
//             continue;
//         }

//         if (arr[i] == arr[i - 1] + 1) {
//             // Consecutive element
//             curr_count++;
//         } else {
//             // Non-consecutive element, update longest and reset curr_count
//             longest = max(longest, curr_count);
//             curr_count = 1;
//         }
//     }

//     // Update longest one more time in case the longest sequence is at the end
//     return max(longest, curr_count);
// }

// Optimise Solution:-O(3N) but space is O(N)
int longestConsecutiveSequence(vector<int> &arr)
{
    int n = arr.size();
    int longest = 1;
    if (n == 0)
        return 0;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    cout << "Enter the elements of array: ";
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Call the function and display the result
    int result = longestConsecutiveSequence(arr);

    cout << "Longest Consecutive Sequence Length: " << result << endl;

    return 0;
}
