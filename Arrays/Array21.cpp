#include<bits/stdc++.h>
using namespace std;

//Everything in the right should be zero:-Leader Element
//Brute force:-O(N^2),O(1)
// vector<int> leaderElement(vector<int> &arr){
//     int n = arr.size();
//     for(int i=0;i<n;i++){
//         bool leader = true;
//         for(int j=i+1;j<n;j++){
//             if(arr[j]>arr[i]){
//                 leader = false;
//                 break;
//             }
//         }
//         if(leader==true){
//             cout<<arr[i]<<" ";
//         }
//     }

// }

//Optimised Method:-O(N) &O(N)-for reveersing we took extra assray
vector<int> leaderElement(vector<int> &arr){
    int maxi = INT_MIN;
    vector<int> ans;
    int n = arr.size();
    for(int i = n-1;i>0;i--){
        if(arr[i]>maxi){
            maxi = arr[i];
            ans.push_back(maxi);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
    vector<int> result = leaderElement(arr);
    for (auto it : result) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}