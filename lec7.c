/*
-Control Flow P2-

Characters
- ASCII value can be printed using %d
- characters are stored as number in memory
- adding a number to a character moves it in the ASCII table

Logical operators

De Morgan's laws
1. The negation of a disjunction is equivalent to the conjunction of the negations
- NOT(A OR B) = (NOT A) AND (NOT B)
- !(a || b) = !a && !b
2. The negation of a conjunction is equivalent to the disjunction of the negations
- NOT(A AND B) = (NOT A) OR (NOT B)
- !(a && b) = !a || !b

Nested if statements

Ternary operator (?)
- conditon ? expression1 : expression2;
- the expression before the ? is evaluated
- if true the value of expression1 is returned
- if false the value of expression2 is returned
- compact way to perform if statements
*/

#include <stdio.h>
#include <stdbool.h>

// program to find the largest of three integers
int main() {
    int a, b, c, largest;
    printf("Please enter three integers\n");
    scanf("%d %d %d", &a, &b, &c);

    // first method
    largest = a;
    if (b >= a && b >= c && printf("4\n")) { // logical operators are left-associative
        largest = b;
    }
    if (c >= a && c >= b) {
        largest = c;
    }

    // alternative method
    largest = (b > largest) ? b : largest;
    largest = (c > largest) ? c : largest;

    printf("maximum is %d", largest);

    if (a/b) {
        printf("This happened");
    }

    return 0;
}
