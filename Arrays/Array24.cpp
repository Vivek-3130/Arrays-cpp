#include<bits/stdc++.h>
using namespace std;


// Brute Force: O(N^2) and O(N^2)
// void rotateMatrix(vector<vector<int>>& matrix, int n ,int m){
//     vector<vector<int>> rotatedMatrix(m, vector<int>(n));
//     for(int i = 0;i<n;i++){
//         for(int j = 0; j<m;j++){
//             rotatedMatrix[j][(n-1)-i]=matrix[i][j];
//         }
//     }
//     matrix = rotatedMatrix;
// }

//Optimised Soln:- O(N^2) and O(1)
void rotateMatrix(vector<vector<int>>& matrix, int n ,int m){
    // Transpose the matrix in-place
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < m; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row in-place
    for (auto& n : matrix) {
        // every row is mat[i]
        reverse(n.begin(), n.end());
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    cout << "Original matrix:" << endl;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
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

    printMatrix(matrix);//Original matrix

    rotateMatrix(matrix,rows,cols);
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