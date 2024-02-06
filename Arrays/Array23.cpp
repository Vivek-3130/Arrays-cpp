#include<bits/stdc++.h>
using namespace std;

#include <vector>

//Brute force:- O(N^2)+(n)+(n)-~ n^3
// void setmatrixzeroes(vector<std::vector<int>>& arr, int rows, int cols) {
//     // Vectors to store information about rows and columns to be zeroed
//     vector<bool> zeroRows(rows, true); //1, marking it as 1 to change the zero
//     vector<bool> zeroCols(cols, true); //1

//     // Identify rows and columns to be zeroed
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < cols; ++j) {
//             if (arr[i][j] == 0) {
//                 zeroRows[i] = false;
//                 zeroCols[j] = false;
//             }
//         }
//     }

//     // Set rows to zero
//     for (int i = 0; i < rows; ++i) {
//         if (!zeroRows[i]) { //mtlb ki if false hua hai
//             for (int j = 0; j < cols; ++j) {
//                 arr[i][j] = 0;
//             }
//         }
//     }

//     // Set columns to zero
//     for (int j = 0; j < cols; ++j) {
//         if (!zeroCols[j]) { //mtlb ki if true hua hai
//             for (int i = 0; i < rows; ++i) {
//                 arr[i][j] = 0;
//             }
//         }
//     }
// }

// void printMatrix(const vector<vector<int>>& matrix) {
//     cout << "Original matrix:" << endl;
//     for (int i = 0; i < matrix.size(); ++i) {
//         for (int j = 0; j < matrix[i].size(); ++j) {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

//Better Solution:-O(2*N*M) and O(N)+O(M)
// void setmatrixzeroes(vector<vector<int>>& matrix, int r,int c){
//     vector<int> col(c, 0);
//     vector<int> row(r, 0);
//     for(int i=0;i<r;i++){
//         for(int j=0;j<c;j++){
//             if(matrix[i][j]==0){
//                 row[i]=1;
//                 col[j]=1;
//             }
//         }
//     }
//     for(int i=0;i<r;i++){
//         for(int j=0;j<c;j++){
//             if(row[i] || col[j]){
//                 matrix[i][j]=0;
//             }
//         }
//     }
// }


//Optimised Solution:-O(2N*M)& O(1)
void setmatrixzeroes(vector<vector<int>>& matrix,int r, int c){
    //int col[c] ->matrix[0][...]
    //int row[r]->matrix[...][0], which we are assuming that is present inside the matrix it self
    int col0=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]==0){
                //marking zero first 
                //mark the ith row
                matrix[i][0]=0;
                //mark the jth col
                if(j !=0 ) //as last wala bhi zero ho jayega usko avoid krne ke liye
                    matrix[0][j]=0;
                else
                    col0=0;
            }
        }
    }
    for(int i =1;i<r;i++){
        for(int j=1;j<c;j++){
            if(matrix[i][j] !=0){
                //check for the rows and cols
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j]=0;
                }
            }
        }
    }
    if(matrix[0][0] == 0){
        for(int j=0;j<c;j++) matrix[0][j] = 0;
    }
    if(col0 == 0){
        for(int i=0;i<r;i++) matrix[i][0] = 0;
    }
}

int main() {  
    // Define the size of the matrix
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    // Create a 2D vector to represent the matrix
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // Populate the matrix with values (you can modify this part as needed)
     cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }

    // printMatrix(matrix);//Original matrix

    setmatrixzeroes(matrix,rows,cols);
     // Print the modified matrix (optional)
    cout << "Modified matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
