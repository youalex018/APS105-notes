/*
-Arrays-
- Fixed sized collection of similar data items in a contigous memory address
- index starts at 0
- size or length of an array is the number of elements in the array
- careful for out of bounds access

data_type array_name[size1][size2][size3]... // for array of N dimensions

Example:
int oddDigits[5] = {}

*/

#include <stdio.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / size(arr[0]))

int main(void) {
    int oddDigits[5] = {1, 3, 5, 7, 9};
    int zeroes[100] = {};
    int uninitialized_array[20];

    return 0;    
}
