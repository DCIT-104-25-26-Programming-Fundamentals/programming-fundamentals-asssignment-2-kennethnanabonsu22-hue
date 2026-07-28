// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// Function prototypes
void printSingleTable(int num);
void printTablesUpToN(int n);

int main() {
    int choice;

    cout << "========================================\n";
    cout << "    MULTIPLICATION TABLE GENERATOR      \n";
    cout << "========================================\n";
    cout << "1. Print table for a single number (Part A)\n";
    cout << "2. Print tables from 1 to N (Part B)\n";
    cout << "Enter your choice (1-2): ";
    cin >> choice;

    if (choice == 1) {
        // --- PART A ---
        int num;
        cout << "\nEnter a number: ";
        cin >> num;

        printSingleTable(num);

    } else if (choice == 2) {
        // --- PART B ---
        int n;
        cout << "\nEnter N (tables from 1 to N): ";
        cin >> n;

        // Validation: N must be a positive integer
        if (n <= 0) {
            cout << "Error: N must be a positive integer." << endl;
        } else {
            printTablesUpToN(n);
        }

    } else {
        cout << "Invalid choice! Exiting program." << endl;
    }

    return 0;
}

// PART A: Function to print the multiplication table for a single number from 1 to 12
void printSingleTable(int num) {
    cout << "\nMultiplication Table for " << num << ":\n";
    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << i << "  =  " << (num * i) << endl;
    }
}

// PART B: Function to print multiplication tables for every number from 1 to N
void printTablesUpToN(int n) {
    for (int i = 1; i <= n; i++) {
        printSingleTable(i);
        if (i < n) {
            cout << "---------------------------" << endl;
        }
    }
}
