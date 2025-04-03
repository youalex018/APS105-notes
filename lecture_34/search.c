/*
-Search algorithms-

Binary Search:
- A search algorithm that finds the position of a target value within a sorted array
- It compares the target value to the middle element of the array
- If the target value is less than the middle element, the search continues in the left half of the array, else it continues in the right half

Out of scope of this course:
Hash Tables
- Hashing is a way to store data in a table using a hash function
- Collision occurs when two values hash to the same index in the table
*/

// Binary search algorithm for first occurence
int binarySearchFirst(int array[], int arrayLength, int val) {
    int low = 0;
    int high = arrayLength - 1;

    while (low <= high) {
        int mid = (high + low) / 2;

        // Check if mid is the first occurrence or at the start
        if ((mid == 0 || val > array[mid - 1]) && val == array[mid]) {
            return mid; // Found the first occurrence
        }
        // Move to the right half if the value is greater
        else if (val > array[mid]) {
            low = mid + 1;
        }
        // Move to the left half if the value is smaller or equal but not first occurrence
        else {
            high = mid - 1;
        }
    }
    return -1; // Value not found
}

// Binary search algorithm for last occurrence
int binarySearchLast(int array[], int arrayLength, int val) {
    int low = 0;
    int high = arrayLength - 1;

    while (low <= high) {
        int mid = (high + low) / 2;

        // Check if mid is the last occurrence or at the end
        if ((mid == arrayLength - 1 || val < array[mid + 1]) && val == array[mid]) {
            return mid; // Found the last occurrence
        }
        // Move to the right half if val >= array[mid]
        else if (val >= array[mid]) { 
            low = mid + 1;
        }
        // Move to the left half
        else {
            high = mid - 1;
        }
    }
    return -1; // Value not found
}