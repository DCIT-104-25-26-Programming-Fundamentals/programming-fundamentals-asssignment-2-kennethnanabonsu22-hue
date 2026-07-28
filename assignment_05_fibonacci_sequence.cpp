// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
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
void printFibonacciTerms(int n);
bool isFibonacciNumber(long long num);

int main() {
    int choice;

    cout << "========================================\n";
    cout << "      FIBONACCI SEQUENCE GENERATOR      \n";
    cout << "========================================\n";
    cout << "1. Print the first N terms (Part A)\n";
    cout << "2. Check if a number is in Fibonacci sequence (Part B)\n";
    cout << "Enter your choice (1-2): ";
    cin >> choice;

    if (choice == 1) {
        // --- PART A ---
        int n;
        cout << "\nHow many terms? ";
        cin >> n;

        // Validation: N must be a positive integer
        if (n <= 0) {
            cout << "Error: Number of terms must be a positive integer." << endl;
        } else {
            printFibonacciTerms(n);
        }

    } else if (choice == 2) {
        // --- PART B ---
        long long checkNum;
        cout << "\nEnter a number to check: ";
        cin >> checkNum;

        if (checkNum < 0) {
            cout << checkNum << " is NOT a Fibonacci number." << endl;
        } else if (isFibonacciNumber(checkNum)) {
            cout << checkNum << " is a Fibonacci number." << endl;
        } else {
            cout << checkNum << " is NOT a Fibonacci number." << endl;
        }

    } else {
        cout << "Invalid choice! Exiting program." << endl;
    }

    return 0;
}

// PART A: Function to generate and print the first N terms using iterative loop
void printFibonacciTerms(int n) {
    long long first = 0, second = 1;

    cout << "Fibonacci sequence: ";

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << first << " ";
            continue;
        }
        if (i == 2) {
            cout << second << " ";
            continue;
        }

        long long next = first + second;
        cout << next << " ";
        first = second;
        second = next;
    }
    cout << endl;
}

// PART B: Function to check if a number belongs to the Fibonacci sequence iteratively
bool isFibonacciNumber(long long num) {
    if (num == 0 || num == 1) {
        return true;
    }

    long long first = 0, second = 1, next = first + second;

    // Generate terms until we reach or exceed the given number
    while (next < num) {
        first = second;
        second = next;
        next = first + second;
    }

    // If next equals num, it is a Fibonacci number
    return (next == num);
}
