#include <iostream>
#include <vector>
using namespace std;

// Function to read a matrix from the keyboard with a default row value
void readMatrix(vector<vector<int>>& matrix, int n, int m) {
    cout << "Enter the elements of the matrix:" <<endl;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Overloaded function with a default row value
void readMatrix(vector<vector<int>>& matrix, int n) {
    readMatrix(matrix, n, 3); // Call the version with a default row value (3)
}

// Function to display a matrix
void displayMatrix(const vector<vector<int>>& matrix) {
    cout << "The matrix is:\n";

    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int n, m;

    cout << "Enter the number of columns (n): ";
    cin >> n;

    cout << "Enter the number of rows (default is 3): ";
    cin >> m;

    // Create a matrix using the overloaded function
    vector<vector<int>> matrix(m, vector<int>(n));

    // Call the appropriate version of the function based on user input
    if (m > 0) {
        readMatrix(matrix, n, m); // Call the version with the user-specified row value
    } else {
        readMatrix(matrix, n);    // Call the version with the default row value (3)
    }

    // Display the entered matrix
    displayMatrix(matrix);

    return 0;
}
