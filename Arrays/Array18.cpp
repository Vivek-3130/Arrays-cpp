#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
//Space Complexity: O(1)

// int stock_sell(vector<int> &prices){
//   int maxProfit = 0;
//   for (int i = 0; i < prices.size(); ++i) {
//     for (int j = i + 1; j < prices.size(); ++j) {
//       maxProfit = max(maxProfit, prices[j] - prices[i]);
//     }
//   }
//   return maxProfit;
// }

//Tc-O(N)&Sc-O(1)
int stock_sell(vector<int> &prices){
  int minPrice = prices[0];
  int maxProfit = 0;
  for (int i = 1; i < prices.size(); ++i) {
    maxProfit = max(maxProfit, prices[i] - minPrice);
    minPrice = min(minPrice, prices[i]);
  }
  return maxProfit;
}
int main() {
    int n;
    cout << "Enter the no of days: ";
    cin >> n;

    cout << "Enter the stock prices ";
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Call the function and display the result
    cout<< stock_sell(a);
    return 0;
}