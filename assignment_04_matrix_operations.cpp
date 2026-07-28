// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string name = "");
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p);

int main() {
    int choice;

    cout << "========================================\n";
    cout << "       MATRIX OPERATIONS PROGRAM        \n";
    cout << "========================================\n";
    cout << "1. Transpose a Matrix (Part A)\n";
    cout << "2. Add Two Matrices (Part B)\n";
    cout << "3. Multiply Two Matrices (Part C)\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        // --- PART A: Transpose a Matrix ---
        int rows, cols;
        int matrix[MAX_SIZE][MAX_SIZE];
        int transposed[MAX_SIZE][MAX_SIZE];

        cout << "\n--- PART A: Transpose a Matrix ---\n";
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        inputMatrix(matrix, rows, cols);

        transposeMatrix(matrix, transposed, rows, cols);

        cout << "\nOriginal Matrix:\n";
        printMatrix(matrix, rows, cols);

        cout << "\nTransposed Matrix:\n";
        printMatrix(transposed, cols, rows);

    } else if (choice == 2) {
        // --- PART B: Add Two Matrices ---
        int rows, cols;
        int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], sum[MAX_SIZE][MAX_SIZE];

        cout << "\n--- PART B: Add Two Matrices ---\n";
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nInput for Matrix A:\n";
        inputMatrix(A, rows, cols, "A");

        cout << "\nInput for Matrix B:\n";
        inputMatrix(B, rows, cols, "B");

        addMatrices(A, B, sum, rows, cols);

        cout << "\nMatrix A:\n";
        printMatrix(A, rows, cols);

        cout << "\nMatrix B:\n";
        printMatrix(B, rows, cols);

        cout << "\nSum (A + B):\n";
        printMatrix(sum, rows, cols);

    } else if (choice == 3) {
        // --- PART C: Multiply Two Matrices ---
        int m, n, p;
        int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], product[MAX_SIZE][MAX_SIZE];

        cout << "\n--- PART C: Multiply Two Matrices (A x B) ---\n";
        cout << "Enter number of rows for Matrix A (M): ";
        cin >> m;
        cout << "Enter number of columns for Matrix A / rows for Matrix B (N): ";
        cin >> n;
        cout << "Enter number of columns for Matrix B (P): ";
        cin >> p;

        cout << "\nInput for Matrix A (" << m << "x" << n << "):\n";
        inputMatrix(A, m, n, "A");

        cout << "\nInput for Matrix B (" << n << "x" << p << "):\n";
        inputMatrix(B, n, p, "B");

        multiplyMatrices(A, B, product, m, n, p);

        cout << "\nMatrix A:\n";
        printMatrix(A, m, n);

        cout << "\nMatrix B:\n";
        printMatrix(B, n, p);

        cout << "\nProduct (A x B):\n";
        printMatrix(product, m, p);

    } else {
        cout << "Invalid choice! Exiting program.\n";
    }

    return 0;
}

// Function to read matrix inputs element by element
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string name) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!name.empty()) {
                cout << "Enter element " << name << "[" << i << "][" << j << "]: ";
            } else {
                cout << "Enter element [" << i << "][" << j << "]: ";
            }
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix in a neatly formatted grid
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A: Transpose logic
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = input[i][j];
        }
    }
}

// Part B: Element-wise Addition
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Part C: Matrix Multiplication (A: M x N, B: N x P -> Result: M x P)
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0; // Initialize element
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
