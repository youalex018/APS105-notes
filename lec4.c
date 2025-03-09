/*
--Basic Arithmetic--
An expression is a combination of operands and operators which results in a single value
Operators follow BEDMAS, and C works left to right (left-associative)

Integer Division
- dividing two integers results in another integer, with no rounding (BE CAREFUL IF YOU WANT EXACTNESS)
- results in the quotient
- modulus operator (%) gets the remainder of the division
- both operands must be ints
- dividing by 0 has an "undefined outcome" - results in compilation error

Type conversion
Implicit type conversion: if one operand is a double and the other is an int, it will be converted to double
Explicit type conversion: writing the desired type in parentheses before the value
- ex. double y = (double) x;
- ex. int b = (int) a;

Assignment operator
- the result is the assigned value
- compound assignment operators: +=, -=, *=, /=, %=
- increment: x++ (post), ++x (pre)
- decrement: y-- (post), --y (pre)

sizeof operator
- evaluates the number of bytes needed to store a data type
*/

#include <stdio.h>

int main(void) {

    // Increment and decrement example
    int x = 9;
    int y = 0;
    printf("%d %d\n", x++, --y);
    return 0;
}
