#include<bits/stdc++.h>
using namespace std;

//TC-O(n),O(1)
int kadanesAlgorithm(vector<int> &arr){
    int sum =0, maxi=INT_MIN;
    int n = arr.size();
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;

    for(int i=0;i<n;i++){
        sum+= arr[i];
        // if(sum > maxi){
        //     maxi = sum;
        // }
        // if(sum < 0){
        //     sum = 0;
        // }
        // // To consider the sum of the empty subarray
        // if(maxi < 0){
        //     maxi = 0;
        // }

        // FOR PRINTING THE ALL TEH SUBARRAYS ASSOCIATED WITH TAHT PARTICULAR ARRAY
        // starting index
        if(sum == 0) start =i;
        if(sum > maxi){
            maxi = sum;
            ansStart=start;
            ansEnd=i;
        }
        if(sum < 0){
            sum = 0;
        }

    }

    // cout << "The subarray is: [";
    // for (int i = ansStart; i <= ansEnd; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    return maxi;
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
    cout<< kadanesAlgorithm(a);
    
    return 0;
}
