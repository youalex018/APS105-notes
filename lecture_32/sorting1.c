/*
-Sorting Part I-

Big O Notation:
- Measures algorithm efficiency
- Describes the upper bound of the time complexity
- Focuses on worst case performance
- Estimates how time or space requirements increase as input size "n" grows

Common Big O Complexities:
- O(1) - Constant time
- O(log n) - Logarithmic time
- O(n) - Linear time
- O(n log n) - Linearithmic time
- O(n^2) - Quadratic time
- O(2^n) - Exponential time

Why Sorting?
Search optimization
- Faster searching in sorted data (Ex. for binary search)
- Reduces time complexity from O(n) to O(log n)
Data Analysis
- Easier identification of patterns and trends
Efficient merging
- Sorted lists are easier to merge/combine
Improves readability
- Makes large datasets easier to understand and analyze
Foundation for complex algorithms
- Used in binary search, divide and conquer algorithms, etc.

Basic building block of sorting - swapping
Bubble sort - Simple sorting algorithm that compares adjacent elements, and swaps them if they are in the wrong order
- Best case: O(n) (already sorted)
- Worse case: O(n^2) (reverse sorted)
- Average case: O(n^2)
- Stable & inplace

Selection sort - Repeatedly selects the smallest (or largest) element from the unsorted part and moves it to its correct sorted position
- Best case: O(n^2)
- Worse case: O(n^2)
- Average case: O(n^2)
- Unstable & inplace

Insertion sort - Repeatedly takes the next element and inserts it into the correct position in the sorted part of the array
- Best case: O(n) (already sorted)
- Worst case: O(n^2) (reverse sorted)
- Average case: O(n^2) (random order)
- Stable & inplace

Stability - An algorithm is stable if it does not change the order of elements with equal value
An algorithm is inplace if it does not use extra space for sorting (only uses a constant amount of extra space)
*/

#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n) {
    int temp;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; i < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break; // No swaps means the array is already sorted
        }
    }
}

void selectionSort(int arr[], int n) {
    int minIndex, temp;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}