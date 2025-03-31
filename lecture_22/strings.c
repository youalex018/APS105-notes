/*
-Strings Part I-

A String is an array of characters terminated by a null character \0
- C adds a 0 byte to the end of the string to indicate the end of the string
- String specifier is %s

String literals are enclosed in double quotes and stored in read-only memory, so you cannot modify them
- Strings can be stored in a character array to be modifiable
- A larger array is fine 

You can print strings in different ways
printf("%s\n", str); 
printf("%.3s\n", str); // prints first 3 characters of str

Getting string inputs from the user:
- Avoid scanf and gets as the string will not have any whitespace and number of characters is unknown
- Use fgets as a safer alternative to read a string from the user
- It prevents buffed overflow by limiting input size, reads a line from a stream (stdin) and stores it in a buffer
char *fgets(char *str, int n, FILE *stream)
- getline() is another option to read an entire line of input by dynamically allocating or resizing memory
size_t getline(char **lineptr, size_t *n, FILE *stream)
- It returns the number of characters read, including the newline character, and stores the string in lineptr
- Returns -1 on failure or end of file (EOF)

*/

// In lecture demo

#include <stdio.h>
#include <stdbool.h>

// Function to count number of spaces in a string
int countSpaces(char* str) {
    int count = 0;
    while (*str != '\0') {
        if (*str == ' ') {
            count++;
        }
        str++;
    }
    return count;
}

// Function to count number of characters in a string
int countChars(char* str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int borderSum(int n, int mat[][26]) {
    if (n == 0) return 0;
    if (n == 1) return mat[0][0];
    
}

int diagonalSum(int n, int square[][n]) {
    int diagSum1 = 0;
    int diagSum2 = 0;
    for (int i = 0; i < n; i++) {
        diagSum1 += square[i][i];
        diagSum2 += square[i][n-i-1];
    }
    return diagSum1 + diagSum2;
}

bool isMagicSquare(int n, int a[][n]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[0][i];
    }

    for (int i = 0; i < n; i++) {
        int newsum = 0;
        for (int j = 0; j = n; j++) {
            newsum += a[i][j];
        }
        if (sum != newsum) {
            return false;
        }
    }

    int newsum2 = 0;
    int newsum3 = 0;

    for (int i = 0; i < n; i++) {
        int newsum = 0;
        for (int j = 0; j < n; j++) {
            newsum += a[j][i];
            newsum2 += a[i][i];
            newsum3 += a[i][n-i-1];
        }
        if (sum != newsum) {
            return false;
        }
    }
    if (sum != newsum2 || sum != newsum3) {
        return false;
    }

}