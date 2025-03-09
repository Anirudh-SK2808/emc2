#include<iostream>
#include<vector>

using namespace std;

void matrixMultiply(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, 
                    int rowA, int colA, int rowB, int colB, int size) {
    if (size == 1) {
        C[rowA][colB] += A[rowA][colA] * B[rowB][colB];
        return;
    }

    int newSize = size / 2;
    matrixMultiply(A, B, C, rowA, colA, rowB, colB, newSize);
    matrixMultiply(A, B, C, rowA, colA + newSize, rowB + newSize, colB, newSize);
    matrixMultiply(A, B, C, rowA, colA, rowB, colB + newSize, newSize);
    matrixMultiply(A, B, C, rowA, colA + newSize, rowB + newSize, colB + newSize, newSize);
    matrixMultiply(A, B, C, rowA + newSize, colA, rowB, colB, newSize);
    matrixMultiply(A, B, C, rowA + newSize, colA + newSize, rowB + newSize, colB, newSize);
    matrixMultiply(A, B, C, rowA + newSize, colA, rowB, colB + newSize, newSize);
    matrixMultiply(A, B, C, rowA + newSize, colA + newSize, rowB + newSize, colB + newSize, newSize);
}

int main() {
    int n;
    cout << "Enter the size of the matrices (n x n): ";
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n, 0));

    cout << "Enter elements of matrix A: ";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of matrix B: ";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> B[i][j];
        }
    }

    matrixMultiply(A, B, C, 0, 0, 0, 0, n);
    cout << "Product of matrix A and matrix B is:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
