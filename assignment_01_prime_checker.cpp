// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// TASK: Prime Number Checker
// =============================================================================

#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    // Numbers less than 2 are NOT prime
    if (n <= 1) {
        return false;
    }
    
    // Check for factors from 2 up to the square root of n
    // Using i * i <= n is more efficient than i <= n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // Found a divisor, so it's not prime
        }
    }
    
    return true; // No divisors found, so it is prime
}

int main() {
    int number;
    
    // Prompt the user for input
    cout << "Enter a number: ";
    cin >> number;
    
    // Call isPrime() and print the result matching the expected output
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is NOT a prime number." << endl;
    }
    
    return 0;
}
