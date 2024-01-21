#include<bits/stdc++.h>
using namespace std;

// int findSingleNumberXOR(const vector<int>& nums) {
//     int result = 0;
//     for (int num : nums) {
//         result ^= num;
//     }
//     return result;
// }

// int main() {
//     std::vector<int> nums = {1, 2, 3, 4, 1, 2, 3};
//     int singleNumber = findSingleNumberXOR(nums);
//     cout << "Number that appears once: " << singleNumber << std::endl;

//     return 0;
// }



// int findSingleNumberHashset(const vector<int>& nums) {
//     unordered_set<int> numSet;
//     for (int num : nums) {
//         // If the number is already in the set, remove it
//         if (numSet.count(num)) {
//             numSet.erase(num);
//         } else {
//             // Otherwise, add it to the set
//             numSet.insert(num);
//         }
//     }
//     // The set will now have only the number that appears once
//     return *numSet.begin();
// }

// int main() {
//     vector<int> nums = {1, 2, 3, 4, 1, 2, 3};
//     int singleNumber = findSingleNumberHashset(nums);
//     cout << "Number that appears once: " << singleNumber << std::endl;

//     return 0;
// }



//Tc:-nlogm and m=(n/2 + 1)
// long long findSingleNumberMap(const vector<long long>& nums) {
//     unordered_map<long long, int> numCountMap;
    
//     for (long long num : nums) {
//         // Increment count for each number in the map
//         numCountMap[num]++;
//     }
    
//     // Find the number with count 1 in the map
//     for (const auto& entry : numCountMap) {
//         if (entry.second == 1) {
//             return entry.first;
//         }
//     }

//     // Handle the case where no unique number is found
//     return 0; // You can choose an appropriate default value or handle it differently
// }

// int main() {
//     vector<long long> nums = {1LL, 2LL, 3LL, 4LL, 1LL, 2LL, 3LL};
//     long long singleNumber = findSingleNumberMap(nums);
    
//     cout << "Number that appears once: " << singleNumber << std::endl;

//     return 0;
// }
