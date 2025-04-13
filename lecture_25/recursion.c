/*
-Recursion-

A recursive function calls itself
- Consists of two parts:
1. Base case: the condition under which the function stops calling itself, where recursion stops
   - It prevents infinite recursion and stack overflow
2. Recursive case: the condition under which the function calls itself, reducing the problem size

Example: Fibonacci numbers
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
- The nth Fibonacci number is the sum of the two preceding numbers, starting with 0 and 1 (base cases)

Call stack: Each recursive call adds a new frame to the call stack, which stores information about the function call, including local variables and return address
The stack has a limited size which can be exceeded by too many recursive calls, causing a stack overflow

Stack overflow occurs when the call stack pointer exceeds the stack bound
- Deep recursion is caused by functions that recurse too deeply without a base case of with a large input size
- Infinite recursion is caused by missing or incorrect base cases, causing the function to call itself indefinitely

Out of scope:
Tail recursion is a special case of recursion where the recursive call is the last operation in the function
- Some compilers optimize it to prevent stack growth

Memoization is an optimization technique used to speed up programs
- Stores the results of expensive function calls and reuses them when the same inputs occur again
- Uses Function Caching to store the results of function calls in a cache (a data structure)
- When a function is called with the same inputs, return the cached result instead of recalculating it
*/

#include <stdio.h>
#include <stdbool.h>

// Function to calculate the greatest common divisor of an integer
int gcd(int a, int b) {
    if (a == b) {
        return a;
    } else if (a > b) {
        return gcd(b, a - b);
    } else {
        return gcd(b, a);
    }
}

// Function to calculate the factorial of a positive integer
int factorial(int n) {
    // Base Case
    if (n == 0) {
        return 1;
    } else {
        // Recursive Call
        return n * factorial(n - 1);
    }
}

// Function to print a row of stars
void printRow(int n) {
    if (n == 1) {
        printf("*\n");
    } else {
        printf("*");
        printRow(n - 1);
    }
}

// Function to print a triangle of stars
void printTriangle(int n) {
    if (n == 1) {
        // printf("*\n");
        printRow(n);
    } else {
        // for (int i = 0; i < n; i++) {
        //     printf("*");
        // }
        // printf("\n");
        printRow(n);
        printTriangle(n - 1);
    }
}

void printInvertedTriangle(int n) {
    if (n > 0) {
        printInvertedTriangle(n - 1);
        printRow(n);
    }
}

bool isPalindrome(char *s, int low, int high) {
    if (low >= high)
        return true; // Base case: is a palindrome
    else if (s[low] != s[high])
        return false; // Base case: is NOT a palindrome
    else // recursive call: compare the remaining characters from low + 1 to high - 1
        return isPalindrome(s, low + 1, high - 1);
}

// Recursive function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n < 2) {
        return n; // Base case: return n if it is 0 or 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case: sum of the two preceding numbers
    }
}

// Recursive function to calculate base^exponent using simple recursion
double power(double base, int exponent) {
    if (exponent == 0) {
        return 1; // Base case: any number raised to the power of 0 is 1
    } else if (exponent < 0) {
        return 1 / power(base, -exponent); // Handle negative exponents
    } else {
        return base * power(base, exponent - 1); // Recursive case: multiply base by the result of power with exponent - 1
    }
}

// Define a large enough size for memoization array
#define MAX 1000

int memo[MAX]; // Array to store previously calculated Fibonacci numbers

// Function to calculate Fiboacnacci number using memoization
int memoFibonacci(int n) {
    if (n < 2) {
        return n; // Base case: return n if it is 0 or 1
    }
    if (memo[n] != -1) {
        return memo[n]; // Return cached result if already calculated
    }

    memo[n] = memoFibonacci(n - 1) + memoFibonacci(n - 2); // Store the result in the cache
    return memo[n]; // Return the calculated Fibonacci number
}

int main(void) {
    int gcdAnswer = gcd(20, 8);
    printf("gcd(20, 8) = %d\n", gcdAnswer);

    printTriangle(5);
    return 0;
}