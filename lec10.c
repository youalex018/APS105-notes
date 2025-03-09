/*
-Functions-

- Must be defined, can be defined at the top with a function prototype
- Used to re-use code 
- Order matters, if the function is not defined before main it will not compile
- Should be small
- Use camelCase for naming

Functions should do only one thing
We pass a copy of a variable into the function, original doesn't change
*/

// Let's write a program that prints rows of stars in a triangle shape
#include <stdio.h>

void printTri(int);
void printRow(int);

int getSum(int, int, int);
double getAverage(int, int);

int main(void) {
    printTri(5);
    
    return 0;
}

void printRow(int rowSize) {
    for (int j = 0; j < rowSize; j++) {
            printf("*");
    }
    printf("\n");
}

void printTri(int numRows) {
    for (int i = 0; i <= numRows; i++) {
        printRow(i);
    }
}
