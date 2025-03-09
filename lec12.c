/*
-Pointers and Hexadecimal-

Hexadecimal
- all digits + ABCDEF
- values from 0-15
- first position has a value of 1, second position has a value of 16
- F is 4 ones
- memory addresses are displayed in hexadecimal
- color codes in web design are in hexadecimal
- machine code 

Pointers - starting address of a variable in memory
- a variable of type int has address of type int*
- are pass by value, passes a copy

ex.
int x = 10;
int* y = &x; points to address of x
int** z = &y; points to address of y
int a = *y; stores value of y
*/