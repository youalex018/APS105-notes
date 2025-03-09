/*
--Functions in C--

Inputs passed to the function are called arguments

printf function:
- outputs a string to the terminal
String format specifiers:
%d - int
%c - char
%lf - double
%f - float

scanf function
- reads data from standard input
- & is using the specific address in the memory to access it

Coding styles:
- use camelCase for variable names
- start constant variable names with an upper caese letter
- use comments
- avoid "magic numbers"

Constant variables:
- prevent accidental changes to a variable

Formatting:
- sub-specifiers (%.2lf) - two decimal places for double
*/

#include <stdio.h>

int main(void) {
    // printf function example
    char character = 'a';
    int integer = 1;
    printf("\"Character\" %c and \"integer\" %d", character, integer);

    // Another example that uses an int to print out a character due to ASCII values
    //int num = 65;
    //printf("%c\n", num);

    // scanf example
    //int age = 0;
    //printf("How old are you?\n");
    //scanf("%d", &age);
    //printf("Age: %d", age);

    // removing decimal places using a sub-specifier
    //double decimalNum = 123.2321;
    //printf("%.2lf\n", decimalNum);

    return 0; // 0 can be replaced by EXIT_SUCCESS
}
