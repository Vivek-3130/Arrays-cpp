#include <vector>
#include <iostream>
using namespace std;

//TC-O(2N) and SC-O(N) -> Brute Force
// vector<int> elementRearrange(vector<int> &arr) {
//     // Separate positive and negative elements
//     vector<int> pos, neg;
//     for (int num : arr) {
//         if (num > 0) {
//             pos.push_back(num);
//         } else if (num < 0) {
//             neg.push_back(num);
//         }
//     }
//     // Interleave positive and negative elements in the original array
//     int i = 0, j = 0, k = 0;
//     while (i < pos.size() && j < neg.size() && k < arr.size()) {
//         arr[k++] = pos[i++];
//         arr[k++] = neg[j++];
//     }
//     // Handle cases where there are not enough positive or negative elements
//     while (i < pos.size()) {
//         arr[k++] = pos[i++];
//     }
//     while (j < neg.size()) {
//         arr[k++] = neg[j++];
//     }
//     return arr;
// }

//Better Method:O(N) & O(1)
// void elementRearrangeThreeWayPartition(vector<int>& arr) {
//     int low = 0, mid = 0, high = arr.size() - 1;

//     while (mid <= high) {
//         if (arr[mid] < 0) {
//             swap(arr[low++], arr[mid++]);
//         } else if (arr[mid] > 0) {
//             swap(arr[mid], arr[high--]);
//         } else {
//             mid++;
//         }
//     }
// }

// Optimised method1 :-O(N) & O(1), if n is even 

// vector<int> elementRearrange(vector<int> &num){
//     int n = num.size();
//     vector<int> ans(n,0);
//     int posIndex = 0, negIndex=1;
//     for (int i =0;i<n;i++){
//         if(num[i] < 0){
//             ans[negIndex]=num[i];
//             negIndex+=2;
//         }
//         else{
//             ans[posIndex]=num[i];
//             posIndex+=2;
//         }
//     }
//     return ans;
// }

// Optimised method2 :-O(2N) & O(N), if n is odd
vector<int> elementRearrange(vector<int> &num){
    vector<int> pos,neg;
    int n = num.size();
    for(int i =0;i<n;i++){
        if(num[i]>0){
            pos.push_back(num[i]);
        }
        else{
            neg.push_back(num[i]);
        }
    }

    if(pos.size() > neg.size()){
        for(int i =0;i<neg.size();i++){
            num[2*i] = pos[i];
            num[2*i+1] = neg[i];
        }
        int index = neg.size() * 2;
        for(int i =neg.size();i<pos.size();i++){
            num[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i =0;i<pos.size();i++){
            num[2*i] = pos[i];
            num[2*i+1] = neg[i];
        }
        int index = neg.size() * 2;
        for(int i =pos.size();i<neg.size();i++){
            num[index] = neg[i];
            index++;
        }
    }
    return num;
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
    vector<int> result = elementRearrange(arr);
    for (auto it : result) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
